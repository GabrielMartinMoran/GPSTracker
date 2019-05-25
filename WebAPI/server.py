from flask import Flask,request
from pymongo import MongoClient
from DataObject import DataObject
from datetime import datetime
import json

MONGO_CONN_STR = "mongodb+srv://gpstracker:Passw0rd@cluster0-1bv3a.mongodb.net/test?retryWrites=true"


#------------------------------------------------------------------------------------------------------

def parse_data_block(data_block):
	data_array = data_block.split("\n")
	data_array = list(filter(None, data_array))
	data_objects = []
	for x in data_array:
		data_row = x.split(",")
		timestamp = datetime.strptime(data_row[0], '%y-%m-%d %H:%M:%S')
		timestamp = timestamp.strftime('%Y-%m-%dT%H:%M:%S.%f%z')
		data_obj = DataObject(timestamp, float(data_row[1]), float(data_row[2]))
		data_objects.append(data_obj)
	return data_objects

#------------------------------------------------------------------------------------------------------

app = Flask(__name__)
client = MongoClient()
client = MongoClient(MONGO_CONN_STR)
db = client['GPSTracker']
collection = db['Data']

@app.route('/',methods=['GET'])
def root():
	return "200"

@app.route('/store-data',methods=['POST'])
def store_data():
	data = request.get_json()#json.loads(request.data)
	data_objects = parse_data_block(data["data"])
	for x in data_objects:
		dict_to_insert = x.to_dict()
		dict_to_insert["device"] = data["device"]
		inserted_id = collection.insert_one(dict_to_insert).inserted_id
		print("> Inserted DataObject with Id: {0}".format(inserted_id))
	return "200"

@app.route('/get-all-data',methods=['GET'])
def get_all_data():
	documents = []
	cursor = collection.find({})
	for x in cursor:
		data_row = {
			"device"	: x["device"],
			"timestamp" : x["timestamp"],
			"latitude"	: x["latitude"],
			"longitude"	: x["longitude"]
		}
		documents.append(data_row)
	return json.dumps(documents)

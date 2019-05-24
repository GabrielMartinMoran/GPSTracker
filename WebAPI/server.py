from flask import Flask,request
from pymongo import MongoClient
from DataObject import DataObject
import json

MONGO_CONN_STR = "mongodb+srv://gpstracker:Passw0rd@cluster0-1bv3a.mongodb.net/test?retryWrites=true"


#------------------------------------------------------------------------------------------------------

def parse_data_block(data_block):
	data_array = data_block.split("\n")
	data_array = list(filter(None, data_array))
	data_objects = []
	for x in data_array:
		data_row = x.split(",")
		data_obj = DataObject(data_row[0], float(data_row[1]), float(data_row[2]))
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
	data = json.loads(request.data)
	data_objects = parse_data_block(data["data"])
	for x in data_objects:
		inserted_id = collection.insert_one(x.to_dict()).inserted_id
		print("> Inserted DataObject with Id: {0}".format(inserted_id))
	return "200"

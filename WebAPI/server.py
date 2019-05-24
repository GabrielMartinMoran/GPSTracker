from flask import Flask,request
from pymongo import MongoClient
import json

MONGO_CONN_STR = "mongodb+srv://gpstracker:Passw0rd@cluster0-1bv3a.mongodb.net/test?retryWrites=true"

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
	inserted_id = collection.insert_one(data).inserted_id
	return str(inserted_id)

import requests
import json
from datetime import datetime
from copy import deepcopy

#   response = requests.get("http://localhost/")
#print(response.text)

import random

CANT_REGISTROS = 20

#aa-mm-dd hh:mm:ss,*lat.nnnnn,*lon.nnnnn\n

def get_normalized_num(num):
    return "{:9.5f}".format(num).replace(' ','0')

def num_to_str(num):
    sign = "+" if num >= 0 else "-"
    return sign + get_normalized_num(abs(num))

def generate_data_line():
    timestamp = datetime.now().strftime('%y-%m-%d %H:%M:%S')
    latitude = num_to_str(random.uniform(-180.000000, 180.000000))
    longitude = num_to_str(random.uniform(-180.000000, 180.000000))
    return "{0},{1},{2}\n".format(timestamp, latitude, longitude)


def generate_data(quantity):
    data = ""
    for x in range(quantity):
        data += generate_data_line()
    return data

def generate_data_from_coords(latitudes, longitudes):
    data = ""
    for x in range(len(latitudes)):
        timestamp = datetime.now().strftime('%y-%m-%d %H:%M:%S')
        latitude = num_to_str(latitudes[x])
        longitude = num_to_str(longitudes[x])
        data += "{0},{1},{2}\n".format(timestamp, latitude, longitude)
    return data


latitudes =  [-34.565709, -34.566072, -34.566328, -34.566558, -34.566845, -34.567070, -34.567251, -34.567622, -34.568037, -34.568302, -34.568576, -34.568788, -34.569146, -34.569429,
              -34.569672, -34.569946, -34.570215, -34.570617, -34.571054, -34.571368, -34.571682, -34.571973, -34.572371, -34.572817, -34.573214, -34.573647, -34.574018, -34.574544,
              -34.574827, -34.575171, -34.575600, -34.576072, -34.576452, -34.576832, -34.577234]
longitudes = [-58.534147, -58.534297, -58.534366, -58.534109, -58.533739, -58.533471, -58.533235, -58.532795, -58.532307, -58.532387, -58.532698, -58.532971, -58.533341, -58.533690,
              -58.534001, -58.534312, -58.534639, -58.535154, -58.535652, -58.536033, -58.536435, -58.536778, -58.536231, -58.535749, -58.535154, -58.534692, -58.534221, -58.533674,
              -58.533990, -58.534376, -58.534864, -58.535406, -58.535824, -58.536274, -58.536789]

data = {
        "device"   : "NO_ESP_TEST",
        "data"     : generate_data_from_coords(latitudes,longitudes)#generate_data(20)
    }
response = requests.post("http://localhost/store-data", json= data)
print("Result = {0}".format(response.text))

"""
response = requests.get("http://localhost/get-all-data")
print(response.json())
"""
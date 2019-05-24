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


data = {
        "device"   : "ESP32_TEST",
        "data"     : generate_data(200)
    }
response = requests.post("http://localhost/store-data", data= json.dumps(data))
print("Result = {0}".format(response.text))
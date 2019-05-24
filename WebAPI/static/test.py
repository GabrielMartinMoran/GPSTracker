import requests
import json
from datetime import datetime

#   response = requests.get("http://localhost/")
#print(response.text)

import random

CANT_REGISTROS = 20

for x in range(CANT_REGISTROS):
    data = {
        "device"   : "ESP32_NO_TEST",
        "x"        : random.uniform(-180.0, 180.0),
        "y"        : random.uniform(-180.0, 180.0),
        "datetime" : datetime.now().strftime('%Y-%m-%dT%H:%M:%S.%f%z')
    }
    response = requests.post("http://localhost/store-data", data= json.dumps(data))
    print("ID del registro {0}: {1}".format(x + 1, response.text))
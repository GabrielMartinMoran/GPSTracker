import pandas

import requests

REQUEST_URL = "http://localhost/get-all-data"

response = requests.get(REQUEST_URL)

devices = []
timestamps = []
latitudes = []
longitudes = []

for x in response.json():
    devices.append(x["device"])
    timestamps.append(x["timestamp"])
    latitudes.append(x["latitude"])
    longitudes.append(x["longitude"])


data_structure = {'device': devices,
                  'timestamp': timestamps,
                  'latitude': latitudes,
                  'longitude': longitudes,
                  }

data = pandas.DataFrame(data_structure, columns=[
                        'device', 'timestamp', 'latitude', 'longitude'])
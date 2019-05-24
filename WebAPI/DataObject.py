class DataObject:

    def __init__(self, timestamp, latitude, longitude):
        self.timestamp = timestamp
        self.latitude = latitude
        self.longitude = longitude

    def to_dict(self):
        return {
            "timestamp" : self.timestamp,
            "latitude"  : self.latitude,
            "longitude" : self.longitude
        }
        
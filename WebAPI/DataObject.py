class DataObject:

    def __init__(self, timestamp, latitude, longitude, stopped):
        self.timestamp = timestamp
        self.latitude = latitude
        self.longitude = longitude
        self.stopped = stopped

    def to_dict(self):
        return {
            "timestamp" : self.timestamp,
            "latitude"  : self.latitude,
            "longitude" : self.longitude,
            "stopped"   : self.stopped
        }
        
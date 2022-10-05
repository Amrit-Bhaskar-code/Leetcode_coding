class UndergroundSystem:

    def __init__(self):
        self.checkInmap = {}
        self.routetotaltime = defaultdict(int)
        self.routecount = defaultdict(int)
        

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkInmap[id] = (stationName, t)
        

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        temp = self.checkInmap.pop(id)
        self.routetotaltime[(temp[0],stationName)] += t - temp[1]
        self.routecount[(temp[0],stationName)] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        return self.routetotaltime[(startStation, endStation)] / self.routecount[(startStation, endStation)]
        


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
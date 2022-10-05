import random
class RandomizedSet:

    def __init__(self):
        self.map = {}
        self.list = []

    def insert(self, val: int) -> bool:
        if val not in self.list:
            self.list.append(val)
            self.map[val] = len(self.list) - 1
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self.list:
            a, b = self.list[-1], self.map[val]
            self.map[a] = b
            self.list[b] = a
            self.list.pop()
            self.map.pop(val)
            return True
        return False

    def getRandom(self) -> int:
        return self.list[random.randint(0, len(self.list)-1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
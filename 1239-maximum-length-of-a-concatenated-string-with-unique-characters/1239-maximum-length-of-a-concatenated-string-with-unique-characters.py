class Solution:
    def maxLength(self, arr: List[str]) -> int:
        dp = [set()]
        for s in arr:
            if(len(s) != len(set(s))):
                continue
            temp = set(s)
            for d in dp:
                if(d & temp):
                    continue
                dp.append(d | temp)
        return max(len(m) for m in dp)
                
class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        mp = dict()
        for elem in target:
            mp[elem] = mp.get(elem, 0) + 1
        
        for elem in arr:
            if elem not in mp or mp[elem] == 0:
                return False
            mp[elem] -= 1
        
        return True
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        mp = dict()
        for s in arr:
            mp[s] = mp.get(s, 0) + 1
        
        steps = k
        for s in arr:
            if mp[s] == 1:
                steps -= 1
                if steps == 0:
                    return s

        return ""
        
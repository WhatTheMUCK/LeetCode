class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq = dict()
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        
        freq = sorted(freq.items(), key=lambda item : (item[1], -item[0]))
        return [key for key, value in freq for _ in range(value)]

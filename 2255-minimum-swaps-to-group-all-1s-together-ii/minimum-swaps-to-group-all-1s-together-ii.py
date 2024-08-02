class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        ones = sum(nums)
        zeros = ones - sum(nums[:ones])
        answer = zeros
        n = len(nums)
        for i in range(ones, n + ones):
            zeros -= 1 - nums[i - ones]
            zeros += 1 - nums[i % n]
            answer = min(answer, zeros)
        return answer

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int start = 0, end = n - 1;
        for (; start <= n - 2 && nums[start] <= nums[start + 1]; ++start);
        for (; end >= 1 && nums[end] >= nums[end - 1]; --end);
        if (start >= end) {
            return 0;
        }

        int minimum = nums[start], maximum = nums[start];
        for (int i = start; i <= end; ++i) {
            minimum = std::min(minimum, nums[i]);
            maximum = std::max(maximum, nums[i]);
        }
        int i;        
        for (i = 0; i < start && nums[i] <= minimum; ++i);
        start = i;
        for (i = n - 1; i > end && nums[i] >= maximum; --i);
        end = i;
        return end - start + 1;
    }
};
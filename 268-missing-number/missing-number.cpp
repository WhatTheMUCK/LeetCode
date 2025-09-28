class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        return (n * (n + 1)) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
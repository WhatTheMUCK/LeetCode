class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curInd = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[curInd], nums[i]);
                ++curInd;
            }
        }
        return;
    }
};
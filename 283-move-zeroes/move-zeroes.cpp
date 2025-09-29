class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curInd = 0, r = 0, n = static_cast<int>(nums.size());
        for (; r < n; ++r) {
            if (nums[r] == 0) {
                continue;
            }
            nums[curInd] = nums[r];
            ++curInd;
        }

        for (; curInd < n; ++curInd) {
            nums[curInd] = 0;
        }
        return;
    }
};
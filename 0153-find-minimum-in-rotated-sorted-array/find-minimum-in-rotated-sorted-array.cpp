class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = static_cast<int>(nums.size()) - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[l] <= nums[m] && nums[m] <= nums[r] || nums[l] > nums[m] && nums[m] <= nums[r]) {
                r = m;
            } else if (nums[l] <= nums[m] && nums[m] > nums[r] || nums[l] > nums[m] && nums[m] > nums[r]) {
                l = m + 1;
            }
        }
        return nums[l];

        // 0 1 2 3 4 5 6 7
        // 3 4 5 6 7 1 2
        //         .   .  
    }
};
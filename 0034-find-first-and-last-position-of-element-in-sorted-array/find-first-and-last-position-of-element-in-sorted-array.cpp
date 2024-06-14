class Solution {
public:
    int search(vector<int> &nums, int target){
        int l = 0, r = nums.size() - 1, m;
        while (l <= r){
            m = (l + r) / 2;
            if (nums[m] >= target){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = search(nums, target);
        int r = search(nums, target + 1);
        if (l == nums.size() || nums[l] != target)
            return {-1, -1};
        return {l, r - 1};
    }
};
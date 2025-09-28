class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (target == nums[m]) {
                return m;
            }

            if (target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (l == n || nums[l] != target) {
            return -1;
        }

        return l;
    }
};
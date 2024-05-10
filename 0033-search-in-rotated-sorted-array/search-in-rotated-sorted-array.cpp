class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while (l < r){
            m = (l + r) / 2;
            //cout << "l: " << l << " r: " << r << " m: " << m << "\n";
            if (target == nums[m])
                return m;
            if (nums[l] <= nums[m]){
                if (nums[l] <= target && target < nums[m]){
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (nums[m] <= nums[r]){
                if (nums[m] < target && target <= nums[r]){
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};
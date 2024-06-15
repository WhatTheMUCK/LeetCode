class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1e6, r = -1e6, maximum = INT_MIN, minimum = INT_MAX;
        for (int i = n - 1; i >= 0; i--){
            if (nums[i] <= minimum){
                minimum = nums[i];
            } else {
                l = i;
            }
        }
        for (int i = 0; i < n; i++){
            if (nums[i] >= maximum){
                maximum = nums[i];
            } else {
                r = i;
            }
        }
        return max(r - l + 1, 0);
    }
};
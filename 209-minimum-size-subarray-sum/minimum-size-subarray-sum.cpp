class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = nums[0];
        int minlength = 1e9;
        while (r < nums.size()){
            if (sum >= target){
                minlength = min(r - l + 1, minlength);
                sum -= nums[l];
                l++;
            } else {
                r++;
                if (r < nums.size()){
                    sum += nums[r];
                }
            }
        }
        if (minlength == 1e9){
            minlength = 0;
        }
        return minlength;
    }
};
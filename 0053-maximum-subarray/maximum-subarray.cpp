class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minSum = INT_MAX / 2, maxSum = INT_MIN;
        int pref = 0;
        for (int elem : nums){
            pref += elem;
            maxSum = max({maxSum, pref, pref - minSum});
            minSum = min(minSum, pref);
        }
        return maxSum;
    }
};
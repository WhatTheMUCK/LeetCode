class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int minpref = 0;
        int answer = INT_MIN;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            answer = max({answer, sum, sum - minpref});
            minpref = min(minpref, sum);
        }
        return answer;
    }
};
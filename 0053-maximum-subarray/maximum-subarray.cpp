class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        int minpref = 0;
        int answer = -1e5;
        for (int i = 1; i <= n; i++){
            pref[i] = nums[i - 1] + pref[i - 1];
            answer = max({answer, pref[i], pref[i] - minpref});
            minpref = min(minpref, pref[i]);
        }
        return answer;
    }
};
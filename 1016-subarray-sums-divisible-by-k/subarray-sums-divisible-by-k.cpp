class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mp(k);
        int pref = 0, answer = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            pref += nums[i];
            answer += mp[((pref % k) + k) % k];
            mp[((pref % k) + k) % k]++;
        }
        return answer;
    }
};
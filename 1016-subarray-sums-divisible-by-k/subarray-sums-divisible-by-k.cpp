class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pref = 0, answer = 0;
        for (int i = 0; i < nums.size(); i++){
            pref += nums[i];
            if (pref % k == 0)
                answer++;
            if (mp.contains(pref % k))
                answer += mp[pref % k];
            if (mp.contains(pref % k - k))
                answer += mp[pref % k - k];
            if (mp.contains(pref % k + k))
                answer += mp[pref % k + k];
            mp[pref % k]++;
        }
        return answer;
    }
};
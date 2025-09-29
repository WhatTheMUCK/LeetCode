class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int curPrefixSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int answer = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            curPrefixSum = (((curPrefixSum + nums[i]) % k) + k) % k;
            answer += mp[curPrefixSum];
            ++mp[curPrefixSum];
        }

        return answer;
    }
};
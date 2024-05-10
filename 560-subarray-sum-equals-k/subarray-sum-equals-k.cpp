class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(), 0);
        unordered_map<int, int> mp;
        prefix[0] = nums[0];
        mp[prefix[0]] = 0;
        for (int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i];
            if (mp.find(prefix[i]) == mp.end()){
                mp[prefix[i]] = 0;
            }
        }

        int answer = 0;
        for (int i = 0; i < nums.size(); i++){
            if (prefix[i] == k)
                answer++;

            if (mp.find(prefix[i] - k) != mp.end()){
                answer += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }

        return answer;
    }
};
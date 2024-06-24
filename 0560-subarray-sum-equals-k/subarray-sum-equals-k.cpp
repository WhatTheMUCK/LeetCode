class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(), 0);
        unordered_map<int, int> mp;
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int answer = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            if (mp.contains(prefix[i] - k))
                answer += mp[prefix[i] - k];
            
            mp[prefix[i]]++;
        }

        return answer;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> search;
        search[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++){
            if (search.contains(target - nums[i]))
                return {search[target - nums[i]], i};
            search[nums[i]] = i;
        }
        return {};
    }
};
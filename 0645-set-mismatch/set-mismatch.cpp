class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int repetition;
        int sum = 0;
        for (int elem : nums){
            if (mp.contains(elem))
                repetition = elem;
            mp[elem]++;
            sum += elem;
        }
        int n = nums.size();
        return {repetition, n * (n + 1) / 2 - (sum - repetition)};
    }
};
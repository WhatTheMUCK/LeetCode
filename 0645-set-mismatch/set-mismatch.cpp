class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int repetition;
        for (int elem : nums){
            if (mp.contains(elem))
                repetition = elem;
            mp[elem]++;
        }

        for (int i = 1; i <= nums.size(); i++){
            if (!mp.contains(i))
                return {repetition, i};
        }
        return {};
    }
};
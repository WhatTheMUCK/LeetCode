class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int acc, int x){ return acc | x; }) << ((int)nums.size() - 1);
    }
};
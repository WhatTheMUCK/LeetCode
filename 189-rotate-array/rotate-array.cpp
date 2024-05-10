class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int rightToLeft = nums.size() - k; 
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
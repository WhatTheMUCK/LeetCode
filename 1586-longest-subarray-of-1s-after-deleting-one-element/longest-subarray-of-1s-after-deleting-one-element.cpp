class Solution {
public:

    int longestSubarray(vector<int>& nums) {
        int ans = 0, prev = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                ans = max(ans, prev + cur);
                prev = cur;
                cur = 0;
            } else {
                cur++;
            }
        }

        if (nums.back() == 1){
            ans = max(ans, prev + cur);
        }

        if (cur == nums.size())
            return nums.size() - 1;

        return ans;
    }
};
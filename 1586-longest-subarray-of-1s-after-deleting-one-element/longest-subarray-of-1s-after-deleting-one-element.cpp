class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0, cur = 0, answer = 0;
        int i = 0;
        for (i; i < nums.size(); i++){
            if (nums[i] == 0){
                prev = cur;
                cur = 0;
            } else {
                cur++;
            }
            answer = max(answer, prev + cur);
        }
        if (cur == nums.size())
            answer--;
        return answer;
    }
};
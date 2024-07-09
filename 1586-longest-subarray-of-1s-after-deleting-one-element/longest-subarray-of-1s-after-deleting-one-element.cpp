class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0, cur = 0, answer = 0;
        int i = 0;
        bool existZero = false;
        while (i < nums.size() && (cur == 0 || nums[i] == 1)){
            if (nums[i] == 0){
                existZero = true;
            } else {
                cur++;
            }
            i++;
        }
        for (i; i < nums.size(); i++){
            if (nums[i] == 0){
                existZero = true;
                answer = max(answer, prev + cur);
                prev = cur;
                cur = 0;
            } else {
                cur++;
            }
        }
        answer = max(answer, prev + cur);
        if (!existZero)
            answer--;
        return answer;
    }
};
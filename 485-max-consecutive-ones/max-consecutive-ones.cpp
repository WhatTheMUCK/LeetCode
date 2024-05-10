class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, answer = -1;
        while (l < nums.size()){
            while (r < nums.size() && nums[r] == 1){
                r++;
            }
            answer = max(answer, r - l);
            l = r + 1;
            r = l;
        }
        return answer;
    }
};
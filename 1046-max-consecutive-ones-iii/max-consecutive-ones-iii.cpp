class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, temp = k, answer = 0;
        while (r < nums.size()){
            if (nums[r] == 1){
                r++;
            } else if (nums[r] == 0 && temp > 0){
                r++;
                temp--;
            } else {
                if (nums[l] == 0)
                    temp++;
                l++;
            }
            answer = max(answer, r - l);
        }
        return answer;
    }
};
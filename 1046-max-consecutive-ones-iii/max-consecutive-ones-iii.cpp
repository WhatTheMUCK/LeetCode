class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, zeros = k, answer = 0, temp = 0;
        while (r < n){
            if (nums[r] == 1){
                r++;
                temp++;
            } else {
                if (zeros > 0){
                    r++;
                    temp++;
                    zeros--;
                } else {
                    for (l; l < n && nums[l] == 1; l++){
                        temp--;
                    }
                    l++;
                    temp--;
                    zeros++;
                }
            }
            answer = max(answer, temp);
        }
        return answer;
    }
};
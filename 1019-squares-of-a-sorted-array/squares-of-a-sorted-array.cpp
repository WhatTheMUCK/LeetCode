class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer;
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            if (abs(nums[l]) > abs(nums[r])){
                answer.push_back(nums[l] * nums[l]);
                l++;
            } else {
                answer.push_back(nums[r] * nums[r]);
                r--;
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
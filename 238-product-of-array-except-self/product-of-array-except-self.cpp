class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> postfix(nums.size(), 1);
        for (int i = nums.size() - 2; i >= 0; i--){
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }
        int multiplication = 1;
        vector<int> answer(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++){
            answer[i] = multiplication * postfix[i];
            multiplication *= nums[i];
        }
        return answer;
    }
};
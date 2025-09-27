class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> leftProduct(n, 1), rightProduct(n, 1);
        for (int i = 1; i < n; ++i) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
            rightProduct[n - (i + 1)] = rightProduct[n - i] * nums[n - i];
        }

        std::vector<int> answer(n, 1);
        for (int i = 0; i < n; ++i) {
            answer[i] = leftProduct[i] * rightProduct[i];
        }

        return answer;
    }
};
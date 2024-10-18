class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maximumBitWiseOr = 0;
        int n = nums.size();
        int answer = 0;
        for (int num : nums){
            maximumBitWiseOr |= num;
        }
        for (int i = 0; i < (1 << n); i++){
            int tempBitWiseOr = 0;
            for (int j = 0; j < n; j++){
                if ((i >> (n - (j + 1))) & 1)
                    tempBitWiseOr |= nums[j];
            }
            answer += tempBitWiseOr == maximumBitWiseOr;
        }
        return answer;
    }
};
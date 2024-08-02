class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        for (int num : nums){
            ones += num;
        }
        if (ones < 2)
            return 0;
        int n = nums.size();
        int zeros = ones;
        for (int i = 0; i < ones; i++){
            zeros -= nums[i];
        }
        int answer = zeros;
        for (int i = 1; i < n; i++){
            nums.push_back(nums[i - 1]);
            if (nums[i - 1] == 0)
                zeros--;
            if (nums[i - 1 + ones] == 0)
                zeros++;
            answer = min(answer, zeros);
        }
        return answer;
    }
};
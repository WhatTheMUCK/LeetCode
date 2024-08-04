class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        for (int i = 0; i < n; i++){
            int sum = nums[i];
            sums.push_back(sum);
            for (int j = i + 1; j < n; j++){
                sum += nums[j];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        int answer = 0;
        for (int i = left - 1; i < right; i++){
            answer = (answer + sums[i]) % (int)(1e9 + 7);
        }
        return answer;
    }
};
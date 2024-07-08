class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int absDifference = INT_MAX;
        int answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++){
            int l = i + 1, r = nums.size() - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target)
                    l++;
                else
                    r--;
                if (absDifference > abs(target - sum)){
                    absDifference = abs(target - sum);
                    answer = sum;
                }
            }
        }
        return answer;
    }
};
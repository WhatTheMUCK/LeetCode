class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        int l, r;
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            l = i + 1, r = nums.size() - 1;
            while (l < r){
                if (nums[l] + nums[r] > -nums[i]){
                    r--;
                } else if (nums[l] + nums[r] < -nums[i]){
                    l++;
                } else {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < nums.size() && nums[l] == nums[l - 1]){
                        l++;
                    }
                    r--;
                    while (r > l && nums[r] == nums[r + 1]){
                        r--;
                    }
                }
            }
        }
        return answer;
    }
};
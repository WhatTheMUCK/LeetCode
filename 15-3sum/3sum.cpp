class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r){
                if (nums[l] + nums[r] == -nums[i]){
                    answer.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < nums.size() && nums[l] == nums[l - 1])
                        l++;
                    r--;
                    while (r >= 0 && nums[r] == nums[r + 1])
                        r--;
                }
                else if (nums[l] + nums[r] < -nums[i]){
                    l++;
                } else {
                    r--;
                }
            }
        }
        return answer;
    }
};
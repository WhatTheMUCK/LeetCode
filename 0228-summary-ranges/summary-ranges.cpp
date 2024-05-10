class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = 0, r = 1;
        vector<string> answer;
        if (nums.empty()){
            return answer;
        }
        while (l < nums.size()){
            if (r < nums.size() && nums[r] == nums[r - 1] + 1){
                r++;
                continue;
            }
            if (nums[l] == nums[r - 1]){
                answer.push_back({to_string(nums[l])});
            } else {
                answer.push_back({to_string(nums[l]) + "->" + to_string(nums[r - 1])});
            }
            l = r;
            r = l + 1;
        }
        return answer;
    }
};
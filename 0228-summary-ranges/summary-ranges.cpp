class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        if (nums.empty())
            return answer;
        int l = 0, r = 1;
        while (r <= nums.size()){
            if (r < nums.size() && nums[r - 1] + 1 == nums[r]){
            } else {
                if (r - 1 == l){
                    answer.push_back(to_string(nums[l]));
                } else {
                    answer.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
                }
                l = r;
            }
            r++;
        }
        return answer;
    }
};
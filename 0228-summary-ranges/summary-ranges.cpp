class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        int l = 0, r = 1;
        while (l < nums.size()){
            while (r < nums.size() && nums[r] == nums[r - 1] + 1){
                r++;
            }
            if (l != r - 1)
                answer.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
            else 
                answer.push_back(to_string(nums[l]));
            l = r;
            r++;
        }
        return answer;
    }
};
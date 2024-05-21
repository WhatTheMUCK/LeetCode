class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int bitmask = 0;
        vector<int> helper;
        vector<vector<int>> answer;
        while (bitmask <= (1 << nums.size()) - 1){
            helper = {};
            for (int i = 0; i < nums.size(); i++){
                if (bitmask & (1 << (nums.size() - (i + 1)))){
                    helper.push_back(nums[i]);
                }
            }
            answer.push_back(helper);
            bitmask++;
        }
        return answer;
    }
};
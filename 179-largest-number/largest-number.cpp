class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> helper(n);
        for (int i = 0; i < n; i++){
            helper[i] = to_string(nums[i]);
        }
        sort(helper.begin(), helper.end(), [](string &lhs, string &rhs){ return lhs + rhs > rhs + lhs; });
        string answer = "";
        if (stoi(helper[0]) == 0)
            return "0";
        for (int i = 0; i < n; i++){
            for (char digit : helper[i]){
                answer.push_back(digit);
            }
        }
        return answer;
    }
};
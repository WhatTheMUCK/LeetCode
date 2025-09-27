class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<std::string> answer;
        if (n == 0) {
            return answer;
        }

        int lhs = nums[0], curInd = 1;
        bool covering = false;
        for (; curInd < n; ++curInd) {
            if (nums[curInd] == nums[curInd - 1] + 1) {
                covering = true;
                continue;
            }

            if (nums[curInd - 1] == lhs) {
                answer.push_back(std::to_string(lhs));
            } else {
                answer.push_back(std::to_string(lhs) + "->" + std::to_string(nums[curInd - 1]));
            }
            lhs = nums[curInd];
            covering = false;
        }

        if (covering) {
            answer.push_back(std::to_string(lhs) + "->" + std::to_string(nums.back()));
        } else {
            answer.push_back(std::to_string(nums.back()));
        }

        return answer;
    }
};
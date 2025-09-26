class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> answer;
        std::sort(intervals.begin(), intervals.end());
        answer.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= answer.back()[1]) {
                answer.back()[0] = std::min(answer.back()[0], intervals[i][0]);
                answer.back()[1] = std::max(answer.back()[1], intervals[i][1]);
                continue;
            }
            answer.push_back(intervals[i]);
        }

        return answer;
    }
};
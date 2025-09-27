class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> mp;
        for (const std::string & word : words) {
            ++mp[word];
        }

        std::vector<std::pair<std::string, int>> helper(mp.begin(), mp.end());
        std::sort(helper.begin(), helper.end(), [](const auto & lhs, const auto & rhs){
            return std::tie(lhs.second, rhs.first) > std::tie(rhs.second, lhs.first);
        });

        std::vector<std::string> answer;
        for (int i = 0; i < k; ++i) {
            answer.push_back(helper[i].first);
        }

        return answer;
    }
};
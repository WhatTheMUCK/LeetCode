class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            ++mp[num];
        }

        vector<pair<int, int>> helper(mp.begin(), mp.end());
        sort(helper.begin(), helper.end(), [](const pair<int, int> & lhs, const pair<int, int> & rhs){
            return tie(lhs.second, lhs.first) > tie(rhs.second, rhs.first);
        });

        vector<int> answer(k);
        for (int i = 0; i < k; ++i) {
            answer[i] = helper[i].first;
        }

        return answer;
    }
};
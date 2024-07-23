class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num]++;
        }
        vector<pair<int, int>> helper(freq.begin(), freq.end());
        sort(helper.begin(), helper.end(), [](pair<int, int> &l, pair<int, int> &r){
            if (l.second == r.second)
                return l.first > r.first;
            return l.second < r.second;
        });
        vector<int> answer;
        answer.reserve(nums.size());
        for (int i = 0; i < helper.size(); i++){
            generate_n(back_inserter(answer), helper[i].second, [&](){ return helper[i].first; });
        }
        return answer;
    }
};
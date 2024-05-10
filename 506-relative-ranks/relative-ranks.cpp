class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> helper;
        for (int i = 0; i < score.size(); i++){
            helper.push_back({score[i], i});
        }
        sort(helper.rbegin(), helper.rend());
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> answer(score.size());
        for (int i = 0; i < helper.size(); i++){
            if (i < 3){
                answer[helper[i].second] = medals[i];
            } else {
                answer[helper[i].second] = to_string(i + 1);
            }
        }
        return answer;
    }
};
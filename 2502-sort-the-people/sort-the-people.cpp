class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string, int>> helper(n);
        for (int i = 0; i < n; i++){
            helper[i] = {names[i], heights[i]};
        }
        sort(helper.begin(), helper.end(), [](pair<string, int> &l, pair<string, int> &r){
            return l.second > r.second;
        });
        vector<string> answer(n);
        for (int i = 0; i < n; i++){
            answer[i] = helper[i].first;
        }
        return answer;
    }
};
bool cmp(pair<int, string> lhs, pair<int, string> rhs){
    if (lhs.first == rhs.first){
        return lhs.second < rhs.second;
    }
    return lhs.first > rhs.first;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string elem : words){
            mp[elem]++;
        }

        vector<pair<int, string>> helper;
        for (pair<string, int> elem : mp){
            helper.push_back({elem.second, elem.first});
        }
        sort(helper.begin(), helper.end(), cmp);
        // for (int i = 0; i < helper.size(); i++){
        //     cout << helper[i].second << " ";
        // }
        vector<string> answer;
        for (int i = 0; i < helper.size() && k > 0; i++){
            k--;
            answer.push_back(helper[i].second);
        }
        return answer;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int n = strs.size();
        string key;
        for (int i = 0; i < n; i++){
            key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> answer;
        for (auto elem : mp){
            answer.push_back(elem.second);
        }
        return answer;
    }
};
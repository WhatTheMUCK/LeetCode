class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> helper;
        for (string& elem : strs){
            string key = elem;
            sort(key.begin(), key.end());
            helper[key].push_back(elem);
        }
        vector<vector<string>> answer;
        for (unordered_map<string, vector<string>>::iterator it = helper.begin(); it != helper.end(); it++){
            answer.push_back(it->second);
        }
        return answer;
    }
};
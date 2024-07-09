class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> helper;
        for (string elem : strs){
            string key = elem;
            sort(key.begin(), key.end());
            helper[key].push_back(elem);
        }
        generate_n(back_inserter(answer), helper.size(), [&helper, it = helper.begin()]() mutable {return it++ -> second; });
        return answer;
    }
};
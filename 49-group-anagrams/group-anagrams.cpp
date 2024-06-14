class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, unordered_map<char, int>> mp;
        int n = strs.size();
        for (int i = 0; i < n; i++){
            for (char ch : strs[i]){
                mp[i][ch]++;
            }
        }
        vector<int> visited(n, 0);
        vector<vector<string>> answer;
        for (int i = 0; i < n; i++){
            if (visited[i] == 1)
                continue;
            answer.push_back({strs[i]});
            for (int j = i + 1; j < n; j++){
                if (mp[i] == mp[j]){
                    answer.back().push_back(strs[j]);
                    visited[j] = 1;
                }
            }
            visited[i] = 1;
        }
        return answer;
    }
};
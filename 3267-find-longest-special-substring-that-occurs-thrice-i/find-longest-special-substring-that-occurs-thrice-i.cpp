class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> freq;
        int n = s.size();
        for (int i = 0; i < n; i++){
            for (int j = i; s[i] == s[j] && j < n; j++){
                freq[s.substr(i, j - i + 1)]++;
            }
        }

        string answer = "";
        for (auto [substr, frequency] : freq){
            if (frequency >= 3 && substr.size() > answer.size()){
                answer = substr;
            }
        }
        return (answer.size() > 0 ? answer.size() : -1);
    }
};
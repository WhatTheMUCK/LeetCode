class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> dict;
        for (char letter : word)
            dict[letter]++;
        vector<pair<char, int>> helper(dict.begin(), dict.end());
        sort(helper.begin(), helper.end(), [](pair<char, int>& lhs, pair<char, int>& rhs){
            return lhs.second > rhs.second;
        });
        int answer = 0;
        int occupied = 0;
        for (pair<char, int> elem : helper){
            answer += (occupied / 8 + 1) * elem.second;
            occupied++;
        }
        return answer;
    }
};
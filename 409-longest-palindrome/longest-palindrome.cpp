class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char elem : s)
            mp[elem]++;
        int answer = 0;
        for (auto &elem : mp){
            if (elem.second % 2 == 1){
                answer++;
                elem.second--;
                break;
            }
        }
        return accumulate(mp.begin(), mp.end(), answer, [](int acc, pair<const char, int> &elem) { return acc + elem.second / 2 * 2; });
    }
};
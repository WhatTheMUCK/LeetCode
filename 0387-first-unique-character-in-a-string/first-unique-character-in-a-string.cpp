class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> mp;
        for (size_t i = 0; i < s.size(); ++i) {
            char letter = s[i];
            if (!mp.contains(letter)){
                mp[letter] = {1, i};
            } else {
                ++mp[letter].first;
            }
        }

        int n = static_cast<int>(s.size());
        int answerPos = n;
        for (auto [letter, info] : mp) {
            if (info.first != 1) {
                continue;
            }
            answerPos = min(answerPos, info.second);
        }

        return (answerPos == n ? -1 : answerPos);
    }
};
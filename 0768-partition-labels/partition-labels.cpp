class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mpAll;
        for (char letter : s) {
            ++mpAll[letter];
        }
        int n = static_cast<int>(s.size());
        vector<int> answer;
        unordered_map<char, int> mpCur;
        int r = 0, size = 0;
        while (r < n) {
            --mpAll[s[r]];
            ++size;
            mpCur[s[r]] = mpAll[s[r]];
            if (mpCur[s[r]] == 0) {
                mpCur.erase(s[r]);
            }

            if (mpCur.size() == 0) {
                answer.push_back(size);
                size = 0;
            }

            ++r;
        }

        return answer;
    }
};
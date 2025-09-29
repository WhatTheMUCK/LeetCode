class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t firstIndex = 0, secondIndex = 0;
        while (firstIndex < s.size() && secondIndex < t.size()) {
            if (s[firstIndex] == t[secondIndex]) {
                ++firstIndex;
            }

            ++secondIndex;
        }

        return firstIndex == s.size();
    }
};
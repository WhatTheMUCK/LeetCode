#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> convert;
        std::unordered_set<char> used;

        int n = static_cast<int>(s.size());
        for (int i = 0; i < n; ++i) {
            if (!convert.contains(s[i])) {
                if (used.contains(t[i])) {
                    return false;
                }
                used.insert(t[i]);
                convert[s[i]] = t[i];
                continue;
            }

            if (convert[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
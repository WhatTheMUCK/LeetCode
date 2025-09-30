class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> lastSeen;
        bool needDelete = false;
        int n = static_cast<int>(s.size());
        int i = 0;
        for (; i < n; ++i) {
            if (!lastSeen.empty() && lastSeen.back() == s[i]) {
                lastSeen.pop_back();
                continue;
            }

            lastSeen.push_back(s[i]);
        }

        return string(lastSeen.begin(), lastSeen.end());
    }
};
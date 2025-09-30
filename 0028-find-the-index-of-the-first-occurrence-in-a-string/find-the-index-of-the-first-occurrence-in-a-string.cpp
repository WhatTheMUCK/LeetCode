class Solution {
public:
    vector<int> zFunction(const string & s) {
        int n = static_cast<int>(s.size());
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }
 
    int strStr(string haystack, string needle) {
        vector<int> z = zFunction(needle + '#' + haystack);
        int n = static_cast<int>(needle.size());
        int m = static_cast<int>(haystack.size());
        for (int i = n + 1; i < n + m + 1; ++i) {
            if (z[i] == n) {
                return i - (n + 1);
            }
        }

        return -1;
    }
};
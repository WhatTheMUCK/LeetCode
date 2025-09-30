class Solution {
public:
    vector<int> zFunction(string input) {
        int n = static_cast<int>(input.size());
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }

            while (i + z[i] < n && input[z[i]] == input[i + z[i]]) {
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

        for (size_t curPos = needle.size() + 1; curPos < z.size(); ++curPos) {
            if (z[curPos] == needle.size()) {
                return curPos - (needle.size() + 1);
            }
        }
        return -1;
    }
};
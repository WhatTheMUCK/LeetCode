class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0, maxLength = 0;
        while (l < s.size()){
            if (r < s.size() && maxCost >= abs(s[r] - t[r])){
                maxCost -= abs(s[r] - t[r]);
                r++;
            } else {
                maxLength = max(maxLength, r - l);
                maxCost += abs(s[l] - t[l]);
                l++;
            }
        }
        return maxLength;
    }
};
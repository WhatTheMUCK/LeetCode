class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0, maxLength = 0;
        while (r < s.size()){
            if (maxCost >= abs(s[r] - t[r])){
                maxCost -= abs(s[r] - t[r]);
                r++;
            } else {
                maxCost += abs(s[l] - t[l]);
                l++;
            }
            maxLength = max(maxLength, r - l);
        }
        return maxLength;
    }
};
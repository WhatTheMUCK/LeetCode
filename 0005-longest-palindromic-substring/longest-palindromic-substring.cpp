class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 1, l, r, startPos = 0;
        for (int i = 1; i < s.size(); i++){
            for (int j = 0; j < 2; j++){
                l = i - j;
                r = i;
                while (l >= 0 && r < s.size() && s[l] == s[r]){
                    l--;
                    r++;
                }
                l++;
                r--;
                if (r - l + 1 > maxLength){
                    maxLength = r - l + 1;
                    startPos = l;
                }
            }
        }
        return s.substr(startPos, maxLength);
    }
};
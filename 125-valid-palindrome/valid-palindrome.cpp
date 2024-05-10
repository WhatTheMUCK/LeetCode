class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r){
            while (l < s.size() && !('a' <= tolower(s[l]) && tolower(s[l]) <= 'z' || '0' <= s[l] && s[l] <= '9')) l++;
            while (r >= 0 && !('a' <= tolower(s[r]) && tolower(s[r]) <= 'z' || '0' <= s[r] && s[r] <= '9')) r--;
            if (l >= r)
                break;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};
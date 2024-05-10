class Solution {
public:

    bool isPalindrome(string s, int l, int r, int freeErase){
        while (l <= r){
            if (s[l] == s[r]){
                l++;
                r--;
            } else {
                if (freeErase == 0)
                    return false;
                return (isPalindrome(s, l, r - 1, freeErase - 1) || isPalindrome(s, l + 1, r, freeErase - 1));
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1, freeErase = 1;
        return isPalindrome(s, l, r, freeErase);
    }
};
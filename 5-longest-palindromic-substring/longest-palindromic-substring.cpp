class Solution {
public:
    string longestPalindrome(string s) {
        int answer = 1, l, r;
        string helper = "";
        helper += s[0];
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
                if (answer < r - l + 1){
                    answer = r - l + 1;
                    helper = s.substr(l, r - l + 1);
                }
            }
        }
        return helper;
    }
};
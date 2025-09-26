class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = static_cast<int>(s.size());
        while (l < r) {
            while (l < r && !std::isalnum(s[l])) {
                ++l;
            }

            while(l < r && !std::isalnum(s[r])) {
                --r;
            }

            if (std::tolower(s[l]) != std::tolower(s[r])) {
                return false;
            }

            ++l;
            --r;
        }
        return true;
    }
};
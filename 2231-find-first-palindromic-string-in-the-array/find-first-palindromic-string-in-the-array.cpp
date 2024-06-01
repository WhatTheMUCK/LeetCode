class Solution {
public:
    bool isPal(string &in){
        int l = 0, r = (int)in.size() - 1;
        while (l < r && in[l] == in[r]){
            l++;
            r--;
        }
        return l == r || in[l] == in[r];
    }
    string firstPalindrome(vector<string>& words) {
        for (string &elem : words){
            if (isPal(elem)){
                return elem;
            }
        }
        return "";
    }
};
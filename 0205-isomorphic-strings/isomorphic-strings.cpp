class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sASCII(128, -1), tASCII(128, -1);
        for (int i = 0; i < s.size(); i++){
            if (sASCII[s[i]] != -1 && sASCII[s[i]] != t[i])
                return false;
            if (tASCII[t[i]] != -1 && tASCII[t[i]] != s[i])
                return false;
            sASCII[s[i]] = t[i];
            tASCII[t[i]] = s[i];
        }
        return true;
    }
};
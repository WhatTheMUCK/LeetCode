class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> start, end;
        for (int i = 0; i < s.size(); i++){
            if (start.find(s[i]) == start.end()){
                if (end.find(t[i]) == end.end()){
                    start[s[i]] = t[i];
                    end[t[i]] = s[i];
                } else {
                    if (end[t[i]] != s[i]){
                        return false;
                    }
                }
            } else {
                if (start[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
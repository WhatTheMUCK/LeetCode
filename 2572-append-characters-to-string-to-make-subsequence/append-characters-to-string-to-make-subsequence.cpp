class Solution {
public:
    int appendCharacters(string s, string t) {
        int fst = 0, snd = 0;
        while (fst < s.size() && snd < t.size()){
            if (s[fst] == t[snd]){
                snd++;
            }
            fst++;
        }
        return (int)t.size() - snd;
    }
};
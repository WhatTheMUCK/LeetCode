class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letter('z' - 'a' + 1, 0);
        for (char sign : t){
            letter[sign - 'a']++;
        }

        for (char sign : s){
            if (letter[sign - 'a'] == 0)
                return false;
            letter[sign - 'a']--;
        }
        return s.size() == t.size();
    }
};
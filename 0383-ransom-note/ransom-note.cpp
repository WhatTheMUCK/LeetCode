class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letter('z' - 'a' + 1, 0);
        for (char sign : magazine)
            letter[sign - 'a']++;
        for (char sign : ransomNote){
            if (letter[sign - 'a'] == 0)
                return false;
            letter[sign - 'a']--;
        }
        return true;
    }
};
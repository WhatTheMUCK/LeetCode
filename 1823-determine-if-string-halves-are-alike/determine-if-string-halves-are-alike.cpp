class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiou";
        int vowels1 = 0, vowels2 = 0;
        int i = 0;
        for (i; i < s.size() / 2; i++){
            if (find(vowels.begin(), vowels.end(), tolower(s[i])) != vowels.end())
                vowels1++;
            if (find(vowels.begin(), vowels.end(), tolower(s[s.size() - 1 - i])) != vowels.end())
                vowels2++;
        }
        return vowels1 == vowels2;
    }   
};
class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int vowels1 = 0, vowels2 = 0;
        int i = 0;
        for (i; i < s.size() / 2; i++){
            if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end())
                vowels1++;
        }
        for (i; i < s.size(); i++){
            if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end())
                vowels2++;
        }
        return vowels1 == vowels2;
    }   
};
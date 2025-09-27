class Solution {
public:
    bool isAnagram(string s, string t) {
        const int dictSize = 'z' - 'a' + 1;
        std::array<int, dictSize> sDict, tDict;
        for (char letter : s) {
            ++sDict[letter - 'a']; 
        }

        for (char letter : t) {
            ++tDict[letter - 'a'];
        }

        return (sDict == tDict);
    }
};
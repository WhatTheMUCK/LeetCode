class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word, prevWord;
        char startSymbol;
        for (int i = 1; ss >> word; i++){
            if (i == 1)
                startSymbol = word[0];
            else if (prevWord.back() != word[0])
                return false;
            prevWord = word;
        }
        if (word.back() != startSymbol)
            return false;
        return true;      
    }
};
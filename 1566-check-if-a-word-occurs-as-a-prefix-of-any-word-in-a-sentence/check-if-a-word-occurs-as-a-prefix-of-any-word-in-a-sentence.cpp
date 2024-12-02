class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int n = searchWord.size();
        int ind = 1;
        while (ss >> word){
            bool prefix = true;
            for (int i = 0; i < n; i++){
                if (searchWord[i] != word[i]){
                    prefix = false;
                }
            }
            if (prefix){
                return ind; 
            }
            ind++;
        }
        return -1;
    }
};
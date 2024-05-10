class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1;
        for (int i = 0; i < word.size(); i++){
            if (word[i] == ch){
                index = i;
                break;
            }
        }
        if (index == -1)
            return word;
        string start = word.substr(0, index + 1);
        reverse(start.begin(), start.end());
        string answer = start + word.substr(index + 1);
        return answer;
    }
};
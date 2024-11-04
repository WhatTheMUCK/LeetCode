class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int start = 0, end = 0, n = word.size();
        while (start < n){
            for (end; end - start + 1 <= 9 && end < n && word[start] == word[end]; end++);
            comp.push_back('0' + (end - start));
            comp.push_back(word[start]);
            start = end;
        }
        return comp;
    }
};
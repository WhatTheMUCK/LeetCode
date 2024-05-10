class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream input(s);
        string in;
        while (input >> in);
        return in.size();
    }
    // Проверка 4
};
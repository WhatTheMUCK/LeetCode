class Solution {
public:
    string reverseWords(string s) {
        stringstream in(s);
        string temp;
        string result = "";
        while (in >> temp){
            result = temp + " " + result;
        }
        result.pop_back();
        return result;
    }
};
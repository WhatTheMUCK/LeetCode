class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows){
            return s;
        }
        int step = numRows + (numRows - 2);
        string res = "";
        for (int i = 0; i <= (step + 1) / 2; i++){
            res += s[i];
            if (i != 0 && i != (step + 1) / 2 && step - i < s.size()){
                res += s[step - i];
            }
            int j = i + step;
            while (j < (int)s.size()){
                res += s[j];
                if (i != 0 && i != (step + 1) / 2 && j - i + step - i < s.size()){
                    res += s[j - i + step - i];
                }
                j += step;
            }
        }
        return res;
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0, checker = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                open++;
                checker++;
            } else if (s[i] == ')' && checker){
                close++;
                checker--;
            }
        }
        open = min(open, close);
        close = min(open, close);
        string answer = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                if (open > 0){
                    answer += s[i];
                    open--;
                }
            } else if (s[i] == ')'){
                if (close > open){
                    answer += s[i];
                    close--;
                }
            } else {
                answer += s[i];
            }
        }
        return answer;
    }
};
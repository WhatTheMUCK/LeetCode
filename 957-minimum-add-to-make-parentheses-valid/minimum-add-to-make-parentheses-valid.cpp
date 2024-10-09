class Solution {
public:
    int minAddToMakeValid(string s) {
        int openParentheses = 0, answer = 0;
        for (char letter : s){
            if (letter == ')'){
                if (openParentheses > 0)
                    openParentheses--;
                else
                    answer++;
            } else 
                openParentheses++;
        }
        return answer + openParentheses;
    }
};
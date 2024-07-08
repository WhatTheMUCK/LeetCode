class Solution {
public:
    void generatePar(int open, int close, string temp, vector<string> &answer){
        if (open == 0){
            for (int i = 0; i < close; i++){
                temp.push_back(')');
            }
            answer.push_back(temp);
            return;
        }
        generatePar(open - 1, close, temp + "(", answer);
        if (close > open){
            generatePar(open, close - 1, temp + ")", answer);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        generatePar(n, n, "", answer);
        return answer;
    }
};
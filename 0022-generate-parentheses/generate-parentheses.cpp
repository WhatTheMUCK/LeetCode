class Solution {
public:
    void generator(int open, int close, vector<string> &answer, string temp){
        if (open == 0){
            generate_n(back_inserter(temp), close, [](){ return ')'; });
            answer.push_back(temp);
            return;
        }
        generator(open - 1, close, answer, temp + "(");
        if (open < close){
            generator(open, close - 1, answer, temp + ")");
        } 
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        generator(n, n, answer, "");
        return answer;
    }
};
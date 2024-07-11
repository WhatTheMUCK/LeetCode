class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> parenthesisPos;
        vector<pair<int, int>> openCloseParenthesis;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                parenthesisPos.push(i);
            } else if (s[i] == ')'){
                openCloseParenthesis.push_back({parenthesisPos.top(), i});
                parenthesisPos.pop();
            }
        }
        string answer = s;
        for (int i = 0; i < openCloseParenthesis.size(); i++){
            cout << openCloseParenthesis[i].first << " " << openCloseParenthesis[i].second << "\n";
            reverse(answer.begin() + openCloseParenthesis[i].first + 1, answer.begin() + openCloseParenthesis[i].second);
        }
        answer.erase(remove_if(answer.begin(), answer.end(), [](char x){ return x == '(' || x == ')'; }), answer.end());
        return answer;
    }
};
class Solution {
public:
    unordered_map<string, int> dp;

    int Remove_Invalid_Parenthesis(string s, int freak, unordered_set<string>& answer){
        if (freak == 0){
            int useless = uselessParenthesis(s);
            if (useless == 0){
                answer.insert(s);
                return 1;    
            }
            return 0;
        }
        if (dp.find(s) != dp.end()){
            return dp[s];
        }
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == ')'){
                string left = s.substr(0, i);
                string right = s.substr(i + 1);
                dp[left + right] = Remove_Invalid_Parenthesis(left + right, freak - 1, answer);
            }
        }
        return dp[s];
    }

    int uselessParenthesis(string s){
        vector<char> parenthesis;
        for (char elem : s){
            if (elem == '('){
                parenthesis.push_back(elem);
            } else if (elem == ')'){
                if (!parenthesis.empty() && parenthesis.back() == '('){
                    parenthesis.pop_back();
                } else {
                    parenthesis.push_back(elem);
                }
            }
        }
        return parenthesis.size();
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> answer;
        int freak = uselessParenthesis(s);
        unordered_set<string> helper;
        Remove_Invalid_Parenthesis(s, freak, helper);
        for (string elem : helper){
            answer.push_back(elem);
        }
        return answer;
    }
};
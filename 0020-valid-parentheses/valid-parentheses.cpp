class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> dict = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> parentheses;
        for (char elem : s){
            if (!dict.contains(elem)){
                parentheses.push(elem);
            } else {
                if (!parentheses.empty() && parentheses.top() == dict[elem])
                    parentheses.pop();
                else
                    return false;
            }
        }
        return parentheses.empty();
    }
};
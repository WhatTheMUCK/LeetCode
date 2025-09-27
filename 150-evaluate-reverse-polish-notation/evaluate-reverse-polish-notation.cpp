#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        for (const std::string & elem : tokens) {
            int rhs, lhs;
            if (elem == "+") {
                rhs = st.top(); st.pop();
                lhs = st.top(); st.pop();
                st.push(lhs + rhs);
            } else if (elem == "-") {
                rhs = st.top(); st.pop();
                lhs = st.top(); st.pop();
                st.push(lhs - rhs);
            } else if (elem == "*") {
                rhs = st.top(); st.pop();
                lhs = st.top(); st.pop();
                st.push(lhs * rhs);
            } else if (elem == "/") {
                rhs = st.top(); st.pop();
                lhs = st.top(); st.pop();
                st.push(lhs / rhs);
            } else {
                st.push(std::stoi(elem));
            }
        }
        return st.top();
    }
};
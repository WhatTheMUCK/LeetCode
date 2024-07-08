class Solution {
public:
    bool isValid(string s) {
        string parenthesis = "({[]})";
        stack<char> st;
        int n = parenthesis.size();
        for (int i = 0; i < s.size(); i++){
            int search = parenthesis.find(s[i]);
            if (search < n / 2){
                st.push(parenthesis[n - (search + 1)]);
            } else {
                if (st.empty() || st.top() != s[i])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
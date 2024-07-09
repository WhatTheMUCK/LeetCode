class Solution {
public:
    string reverseWords(string s) {
        string answer = "";
        s.push_back(' ');
        string helper;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                generate_n(back_inserter(answer), helper.size(), [&s, &helper, i = helper.size() - 1]() mutable {return helper[i--]; });
                answer.push_back(' ');
                helper = "";
            } else {
                helper.push_back(s[i]);
            }
        }
        answer.pop_back();
        return answer;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        string answer, temp;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                reverse(temp.begin(), temp.end());
                generate_n(back_inserter(answer), temp.size(), [i = 0, &temp]() mutable { return temp[i++]; });
                temp = "";
                answer.push_back(' ');
            } else {
                temp.push_back(s[i]);
            }
        }
        answer.pop_back();
        return answer;
    }
};
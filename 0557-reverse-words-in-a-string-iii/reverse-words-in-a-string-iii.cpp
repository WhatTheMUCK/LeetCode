class Solution {
public:
    string reverseWords(string s) {
        string answer = "";
        s.push_back(' ');
        deque<char> helper;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                for (char elem : helper){
                    answer.push_back(elem);
                }
                answer.push_back(' ');
                helper = deque<char>();
            } else {
                helper.push_front(s[i]);
            }
        }
        answer.pop_back();
        return answer;
    }
};
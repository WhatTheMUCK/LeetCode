class Solution {
public:
    string makeGood(string s) {
        deque<char> temp = {s[0]};
        for (int i = 1; i < (int)s.size(); i++){
            if (temp.size() == 0){
                temp.push_back(s[i]);
            } else {
                if (tolower(s[i]) == tolower(temp.at(temp.size() - 1)) && (isupper(s[i]) && islower(temp.at(temp.size() - 1)) || islower(s[i]) && isupper(temp.at(temp.size() - 1)))){
                    temp.pop_back();
                } else {
                    temp.push_back(s[i]);
                }
            }
        }
        string answer = "";
        if (temp.size() > 0){
            for (char elem : temp){
                answer += elem;
            }
        }
        return answer;
    }
};
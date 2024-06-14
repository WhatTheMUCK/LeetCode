class Solution {
public:
    int maxPower(string s) {
        s.push_back('#');
        int answer = 1;
        int temp = 1;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i - 1]){
                temp++;
            } else {
                answer = max(answer, temp);
                temp = 1;
            }
        }
        return answer;
    }
};
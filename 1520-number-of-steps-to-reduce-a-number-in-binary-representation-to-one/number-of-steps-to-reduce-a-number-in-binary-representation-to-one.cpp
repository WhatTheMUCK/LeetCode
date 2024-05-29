class Solution {
public:
    int numSteps(string s) {
        int answer = 0;
        while (s.size() > 1){
            if (s.back() == '0')
                s.pop_back();
            else{
                int i = s.size() - 1;
                for (i; i >= 0 && s[i] == '1'; i--){
                    s[i] = '0';
                }
                if (i < 0){
                    s.insert(s.begin(), '1');
                } else {
                    s[i] = '1';
                }
            }
            answer++;
        }
        return answer;
    }
};
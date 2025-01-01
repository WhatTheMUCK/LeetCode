class Solution {
public:
    int maxScore(string s) {
        int zeros = s[0] == '0', ones = accumulate(s.begin() + 1, s.end(), 0, [](int acc, char x){ return acc + (x == '1'); });
        int answer = zeros + ones;
        int n = s.size();
        for (int i = 1; i < n - 1; i++){
            zeros += s[i] == '0';
            ones -= s[i] == '1';
            answer = max(answer, zeros + ones);
        }
        return answer;
    }
};
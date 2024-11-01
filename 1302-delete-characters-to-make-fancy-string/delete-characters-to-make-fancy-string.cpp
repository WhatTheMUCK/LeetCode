class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if (n < 3)
            return s;
        string answer;
        char prev = s[0], prev2 = s[1];
        answer.push_back(prev);
        answer.push_back(prev2);
        for (int i = 2; i < n; i++){
            if (prev == prev2 && prev2 == s[i])
                continue;
            answer.push_back(s[i]);
            tie(prev, prev2) = make_tuple(prev2, s[i]);
        }
        return answer;
    }
};
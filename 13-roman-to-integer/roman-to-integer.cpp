class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        int answer = 0;
        int temp = roman[s[0]];
        for (int i = 1; i < s.size(); i++){
            if (roman[s[i]] == roman[s[i - 1]]){
                temp += roman[s[i]];
            } else if (roman[s[i]] > roman[s[i - 1]]){
                answer += roman[s[i]] - temp;
                temp = 0;
            } else if (roman[s[i]] < roman[s[i - 1]]){
                answer += temp;
                temp = roman[s[i]];
            }
        }
        answer += temp;
        return answer;
    }
};
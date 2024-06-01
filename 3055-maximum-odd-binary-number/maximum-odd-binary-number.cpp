class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<int> count(2, 0);
        for (char elem : s){
            count[elem - '0']++;
        }
        string answer = "";
        generate_n(back_inserter(answer), count[1] - 1, [](){ return '1'; });
        generate_n(back_inserter(answer), count[0], [](){ return '0'; });
        answer.push_back('1');
        return answer;
    }
};
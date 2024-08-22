class Solution {
public:
    int findComplement(int num) {
        int answer = 0, digit;
        long long degreeOfTwo = 1;
        while (num > 0){
            digit = num % 2;
            answer += (1 - digit) * degreeOfTwo;
            degreeOfTwo *= 2;
            num /= 2;
        }
        return answer;
    }
};
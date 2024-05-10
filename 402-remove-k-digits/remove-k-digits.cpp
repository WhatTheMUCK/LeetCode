class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> numbers, temp;
        for (char elem : num){
            while (!numbers.empty() && k > 0 && elem < numbers.top()){
                numbers.pop();
                k--;
            }
            numbers.push(elem);

        }

        while (k > 0){
            numbers.pop();
            k--;
        }

        string answer = "";
        while (!numbers.empty()){
            answer += numbers.top();
            numbers.pop();
        }
        answer += "0";
        cout << answer << "\n";
        while (answer.size() > 1 && answer.back() == '0'){
            answer.pop_back();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int num1, num2;
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                numbers.push(stoi(tokens[i]));
            } else {
                num2 = numbers.top();
                numbers.pop();
                num1 = numbers.top();
                numbers.pop();
                if (tokens[i] == "+"){
                    numbers.push(num1 + num2);
                } else if (tokens[i] == "-"){
                    numbers.push(num1 - num2);
                } else if (tokens[i] == "*"){
                    numbers.push(num1 * num2);
                } else if (tokens[i] == "/"){
                    numbers.push(num1 / num2);
                }
            }
        }
        return numbers.top();
    }
};
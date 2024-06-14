#define all(x) x.begin(), x.end()

class Solution {
public:
    string addition(string &num1, string &num2){
        deque<char> result;
        int n1 = num1.size(), n2 = num2.size();
        if (n1 > n2)
            swap(num1, num2);
        n1 = num1.size(), n2 = num2.size();
        int i = 1, temp = 0, sum;
        for (i; i <= n1; i++){
            sum = (num1[n1 - i] - '0') + (num2[n2 - i] - '0');
            result.push_front((char)((sum + temp) % 10 + '0'));
            temp = (sum + temp) / 10;
        }
        for (i; i <= n2; i++){
            sum = (num2[n2 - i] - '0');
            result.push_front((char)((sum + temp) % 10 + '0'));
            temp = (sum + temp) / 10;
        }
        if (temp > 0)
            result.push_front((char)(temp + '0'));
        return string(all(result));
    }


    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.size(), n2 = num2.size();
        if (n1 > n2)
            swap(num1, num2);
        n1 = num1.size(), n2 = num2.size();
        string prev = "0";
        int mult;
        for (int i = 1; i <= n1; i++){
            int multiplier = (num1[n1 - i] - '0');
            int temp = 0;
            deque<char> result;
            for (int j = 1; j <= n2; j++){
                int mult = multiplier * (num2[n2 - j] - '0');
                result.push_front((char)((mult + temp) % 10 + '0'));
                temp = (mult + temp) / 10;
            }
            if (temp > 0)
                result.push_front((char)(temp + '0'));
            for (int k = 1; k < i; k++)
                result.push_back('0');
            string helper(all(result));
            prev = addition(helper, prev);
        }
        return prev;
    }
};
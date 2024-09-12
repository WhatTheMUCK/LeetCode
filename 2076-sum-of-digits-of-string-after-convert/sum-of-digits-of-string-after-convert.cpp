class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        int transform;
        for (char letter : s){
            transform = letter - 'a' + 1;
            if (transform / 10 > 0)
                temp.push_back(transform / 10 + '0');
            temp.push_back(transform % 10 + '0');
        }
        s = temp;
        int sum;
        for (int i = 0; i < k; i++){
            sum = 0;
            for (char digit : s){
                sum += digit - '0';
            }
            s = to_string(sum);
        }
        return sum;
    }
};
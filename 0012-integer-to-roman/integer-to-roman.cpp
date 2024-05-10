class Solution {
public:
    string intToRoman(int num) {
        string answer = "";
        vector<pair<int, string>> roman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        for (int i = 0; i < roman.size(); i++){
            for (int j = 0; j < num / roman[i].first; j++){
                answer += roman[i].second;
            }
            num %= roman[i].first;
        }
        return answer;
    }
};
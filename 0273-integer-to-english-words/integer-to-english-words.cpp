class Solution {
private:
    vector<string> pronunciation;
    vector<string> order;

    void inizialization(){
        pronunciation.resize(100, "");
        pronunciation[0] = "Zero";
        pronunciation[1] = "One";
        pronunciation[2] = "Two";
        pronunciation[3] = "Three";
        pronunciation[4] = "Four";
        pronunciation[5] = "Five";
        pronunciation[6] = "Six";
        pronunciation[7] = "Seven";
        pronunciation[8] = "Eight";
        pronunciation[9] = "Nine";
        pronunciation[10] = "Ten";
        pronunciation[11] = "Eleven";
        pronunciation[12] = "Twelve";
        pronunciation[13] = "Thirteen";
        pronunciation[14] = "Fourteen";
        pronunciation[15] = "Fifteen";
        pronunciation[16] = "Sixteen";
        pronunciation[17] = "Seventeen";
        pronunciation[18] = "Eighteen";
        pronunciation[19] = "Nineteen";
        pronunciation[20] = "Twenty";
        pronunciation[30] = "Thirty";
        pronunciation[40] = "Forty";
        pronunciation[50] = "Fifty";
        pronunciation[60] = "Sixty";
        pronunciation[70] = "Seventy";
        pronunciation[80] = "Eighty";
        pronunciation[90] = "Ninety";

        for (int i = 0; i < 100; i++){
            if (pronunciation[i].empty()){
                pronunciation[i] = pronunciation[(i / 10) * 10] + " " + pronunciation[i % 10];
            }
        }

        order.resize(4, "");
        order[1] = "Thousand";
        order[2] = "Million";
        order[3] = "Billion";
    }

public:
    string numberToWords(int num) {
        inizialization();
        if (num == 0)
            return pronunciation[0];

        pronunciation[0] = "";
        deque<string> helper;
        int counter = 0;
        while (num > 0){
            if (counter > 0 && num % 1000 > 0){
                helper.push_front(order[counter]);
            }
            int twoDigitNumber = num % 100;
            if (twoDigitNumber > 0){
                helper.push_front(pronunciation[num % 100]);
            }
            int hundreds = (num % 1000) / 100;
            if (hundreds > 0){
                helper.push_front("Hundred");
                helper.push_front(pronunciation[hundreds]);
            }

            counter++;
            num /= 1000;
        }
        string answer = "";
        for (string &elem : helper){
            for (char letter : elem){
                answer.push_back(letter);
            }
            answer.push_back(' ');
        }
        answer.pop_back();
        return answer;
    }
};
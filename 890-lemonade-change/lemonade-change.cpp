class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> dollars(4, 0);
        int remains = 0;
        for (int bill : bills){
            // cout << "bill: " << bill << "\n";
            // cout << "dollars: " << dollars[0] << " " << dollars[1] << "\n";
            remains = bill - 5;
            int tens = remains / 10;
            int fives = (remains - tens * 10) / 5;
            // cout << "tens: " << tens << "\n";
            // cout << "fives: " << fives << "\n";
            int tensInd = 10 / 5 - 1;
            int amountTakenTens = min(dollars[tensInd], tens);
            dollars[tensInd] -= amountTakenTens;
            tens -= amountTakenTens;
            // cout << "tens: " << tens << "\n";
            fives += tens * 10 / 5;
            // cout << "fives: " << fives << "\n";
            int fiveInd = 5 / 5 - 1;
            int amountTakenFives = min(dollars[fiveInd], fives);
            dollars[fiveInd] -= amountTakenFives;
            fives -= amountTakenFives;
            // cout << "fives: " << fives << "\n";
            if (fives > 0){
                return false;
            }
            dollars[bill / 5 - 1]++;
            // cout << "\n";
        } 
        return true;
    }
};
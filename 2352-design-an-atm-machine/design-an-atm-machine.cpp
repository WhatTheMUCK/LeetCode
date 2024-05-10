class ATM {
public:
    unordered_map<int, int> dollars;
    vector<int> values = {20, 50, 100, 200, 500};
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++){
            dollars[values[i]] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> temp = {0, 0, 0, 0, 0};
        for (int i = values.size() - 1; i >= 0; i--){
            if (dollars[values[i]] > 0){
                int minus = min(amount / values[i], dollars[values[i]]);
                temp[i] += minus;
                amount -= minus * values[i];
            }
        }
        for (int i = 0; i < temp.size(); i++){
            if (dollars[values[i]] < temp[i]){
                return {-1};
            }
        }
        if (amount > 0)
            return {-1};
        for (int i = 0; i < temp.size(); i++){
            dollars[values[i]] -= temp[i];
        }
        return temp;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
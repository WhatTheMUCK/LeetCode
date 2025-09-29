template <typename T>
vector<T> & operator+=(vector<T> & lhs, const vector<T> & rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::logic_error("Not equal sizes!");
    }

    for (int i = 0; i < lhs.size(); ++i) {
        lhs[i] += rhs[i];
    }

    return lhs;
}

class ATM {
public:
    ATM() {
        banknotes = {0,  0,  0,   0,   0};
        values =    {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for (size_t i = 0; i < banknotesCount.size(); ++i) {
            banknotes[i] += banknotesCount[i];
        }
        return;
    }
    
    vector<int> withdraw(int amount) {
        vector<int> tmp = {0, 0, 0, 0, 0};
        int n = banknotes.size();
        for (int i = n - 1; i >= 0; --i) {
            if (amount / values[i] > 0 && banknotes[i] > 0) {
                int curBancknotes = min((amount / values[i]), banknotes[i]);
                amount -= curBancknotes * values[i];
                tmp[i] += curBancknotes;
                banknotes[i] -= curBancknotes;
            }
        }

        if (amount != 0) {
            banknotes += tmp;
            return {-1};
        }

        return tmp;
    }

    vector<int> banknotes;
    vector<int> values;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
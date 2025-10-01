#include <random>

class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.contains(val)) {
            return false;
        }

        mp[val] = valHolder.size();
        valHolder.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!mp.contains(val)) {
            return false;
        }

        int curIndex = mp[val];
        mp.erase(val);

        int n = static_cast<int>(valHolder.size());
        if (curIndex != n - 1) {
            mp[valHolder.back()] = curIndex;
            swap(valHolder[curIndex], valHolder.back());
        }

        valHolder.pop_back();
        return true;
    }
    
    int getRandom() {
        return valHolder[rand() % valHolder.size()]; 
    }

    unordered_map<int, int> mp;
    vector<int> valHolder;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
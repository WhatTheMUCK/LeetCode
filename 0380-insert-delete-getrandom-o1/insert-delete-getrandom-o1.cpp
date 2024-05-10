class RandomizedSet {
    vector<int> elems;
    unordered_map<int, int> dictionary;
public:
    RandomizedSet() {   
    }
    
    bool insert(int val) {
        if (dictionary.find(val) != dictionary.end()){
            return false;
        }
        elems.push_back(val);
        dictionary[val] = elems.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (dictionary.find(val) == dictionary.end()){
            return false;
        }
        elems[dictionary[val]] = elems.back();
        elems.pop_back();
        dictionary[elems[dictionary[val]]] = dictionary[val];
        dictionary.erase(val);
        return true;
    }
    
    int getRandom() {
        return elems[rand() % elems.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
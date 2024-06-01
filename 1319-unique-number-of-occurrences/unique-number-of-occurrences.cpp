class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        for (int elem : arr)
            occur[elem]++;
        unordered_set<int> helper;
        for (pair<int, int> elem : occur)
            helper.insert(elem.second);
        return occur.size() == helper.size();
    }
};
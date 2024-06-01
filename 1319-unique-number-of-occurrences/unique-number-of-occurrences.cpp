class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        for (int elem : arr)
            occur[elem]++;
        vector<int> helper;
        generate_n(back_inserter(helper), occur.size(), [it = occur.begin()]() mutable { return (it++)->second; });
        sort(helper.begin(), helper.end());
        return unique(helper.begin(), helper.end()) == helper.end();
    }
};
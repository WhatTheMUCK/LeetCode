class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remains;
        for (int elem : arr)
            remains[((elem % k) + k) % k]++;
        for (auto [elem, count] : remains)
            if (remains[(2 * k - elem) % k] != count || (elem == 0 || elem == k - elem) && remains[elem] % 2 != 0)
                return false;
        return true;
    }
};
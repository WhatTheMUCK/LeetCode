class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int elem : nums)
            mp[elem]++;
        int maxFreq = max_element(mp.begin(), mp.end(), [](const pair<int, int> &l, const pair<int, int> &r){ return l.second < r.second; })->second;
        return accumulate(mp.begin(), mp.end(), 0, [maxFreq](int acc, const pair<int, int> &x) { return acc + (x.second == maxFreq ? x.second : 0); });
    }
};
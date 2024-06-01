class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int elem : nums)
            mp[elem]++;
        int maxFreq = max_element(mp.begin(), mp.end(), [](const pair<int, int> &l, const pair<int, int> &r){ return l.second < r.second; })->second;
        return count_if(mp.begin(), mp.end(), [&maxFreq](pair<const int, int> &x){ return x.second == maxFreq;}) * maxFreq;
    }
};
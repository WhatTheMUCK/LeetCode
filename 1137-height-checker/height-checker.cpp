class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        return accumulate(sorted.begin(), sorted.end(), 0, [&heights, i = 0](int acc, int x) mutable {
            return acc + (x != heights[i++]);
        });
    }
};
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp(100);
        for (int elem : heights)
            temp[elem - 1]++;
        vector<int> sorted;
        for (int i = 0; i < 100; i++){
            generate_n(back_inserter(sorted), temp[i], [i](){ return i + 1; });
        }
        return accumulate(sorted.begin(), sorted.end(), 0, [&heights, i = 0](int acc, int x) mutable {
            return acc + (x != heights[i++]);
        });
    }
};
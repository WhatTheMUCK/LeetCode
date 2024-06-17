class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelrys(jewels.begin(), jewels.end());
        return accumulate(stones.begin(), stones.end(), 0, [&jewelrys](int acc, int x){ return acc + jewelrys.contains(x); });
    }
};
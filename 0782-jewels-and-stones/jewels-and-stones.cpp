class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st(jewels.begin(), jewels.end());
        return count_if(stones.begin(), stones.end(), [&st](char letter){ return st.contains(letter); });
    }
};
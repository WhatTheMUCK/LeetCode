class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelrys(jewels.begin(), jewels.end());
        int answer = 0;
        for (char elem : stones)
            answer += jewelrys.contains(elem);
        return answer;
    }
};
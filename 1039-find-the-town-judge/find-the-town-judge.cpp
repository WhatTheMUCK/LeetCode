class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> people(n, 0);
        unordered_map<int, int> trusts;
        for (vector<int> &elem : trust){
            trusts[elem[1] - 1]++;
            people[elem[0] - 1]++;
            if (!trusts.contains(elem[0] - 1))
                trusts[elem[0] - 1] = 0;
        }
        for (int i = 0; i < n; i++){
            if (!people[i] && (trusts[i] == n - 1))
                return i + 1;
        }
        return -1;
    }
};
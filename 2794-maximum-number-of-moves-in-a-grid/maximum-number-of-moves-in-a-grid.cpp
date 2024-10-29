namespace std {
template <> struct hash<pair<int, int>>{
    inline size_t operator()(const pair<int, int> &v) const {
        hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second) * 63;
    }
};
}

class Solution {
public:
    vector<vector<int>> grid;
    unordered_map<pair<int, int>, int> mp;
    int n, m;
    bool include(int i, int j){
        return 0 <= i && i < n && 0 <= j && j < m;
    }

    int dfs(int i, int j, int prevValue){
        if (!include(i, j) || grid[i][j] <= prevValue)
            return -1;
        if (mp.contains({i, j}))
            return mp[{i, j}];
        mp[{i, j}] = 1 + max({dfs(i - 1, j + 1, grid[i][j]), dfs(i, j + 1, grid[i][j]), dfs(i + 1, j + 1, grid[i][j])});
        return mp[{i, j}];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int answer = 0;
        int n = grid.size(), m = grid[0].size();
        this->grid = grid;
        this->n = n, this->m = m;
        for (int i = 0; i < n; i++){
            answer = max(answer, dfs(i, 0, -1));
        }
        return answer;
    }
};
class Solution {
public:
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int maxGold = 0;

    int DFS(int x, int y, vector<vector<int>> &grid) {
        // Проверка границ должна быть первой
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return 0;
        int curr = grid[x][y];
        grid[x][y] = 0;
        int localMaxGold = curr;

        for (int i = 0; i < 4; i++) {
            int newX = x + roww[i];
            int newY = y + coll[i];
            localMaxGold = max(localMaxGold, curr + DFS(newX, newY, grid));
        }

        grid[x][y] = curr;
        return localMaxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int answer = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0 ; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] != 0)
                    answer = max(answer, DFS(i, j, grid));
            }
        }
        return answer;
    }
};
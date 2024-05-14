class Solution {
public:
    int DFS(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int sum) {
        // Проверка границ должна быть первой
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j] == 1)
            return sum;
        sum += grid[i][j];
        visited[i][j] = 1;
        int maxGold = sum;
        // Переменные для хранения промежуточных результатов
        int down = DFS(i + 1, j, grid, visited, sum);
        int right = DFS(i, j + 1, grid, visited, sum);
        int up = DFS(i - 1, j, grid, visited, sum);
        int left = DFS(i, j - 1, grid, visited, sum);
        maxGold = max({maxGold, down, right, up, left});
        visited[i][j] = 0; // Важно сбросить посещение для других путей
        return maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int answer = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0 ; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] != 0)
                    answer = max(answer, DFS(i, j, grid, visited, 0));
            }
        }
        return answer;
    }
};
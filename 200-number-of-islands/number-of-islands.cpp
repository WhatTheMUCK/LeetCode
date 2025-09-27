class Solution {
public:
    //         {-1 0} 
    // {0 -1}     x   {0, 1}
    //          {1 0}  

    // для row: -1 0 1 0
    // для col:  0 1 0 -1
    std::vector<int> rowOffset = {-1, 0, 1, 0}; 
    std::vector<int> colOffset = {0, 1, 0, -1};
    

    void mark(const vector<vector<char>> & grid, vector<vector<bool>> & visited, int row, int col) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid[0].size());

        if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] == true || grid[row][col] == '0') {
            return;
        }

        visited[row][col] = true;
        for (int k = 0; k < 4; ++k) {
            mark(grid, visited, row + rowOffset[k], col + colOffset[k]);
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid[0].size());
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0' || visited[i][j] == true) {
                    continue;
                }

                ++answer;
                mark(grid, visited, i, j);
            }
        }

        return answer;
    }
};
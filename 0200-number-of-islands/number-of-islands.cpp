bool island(vector<vector<int>> &field, vector<vector<int>> &visited, int i, int j){
    visited[i][j] = 1;
    if (field[i][j] == 0){
        return false;
    }
    if (!visited[i + 1][j]){
        island(field, visited, i + 1, j);
    }
    if (!visited[i - 1][j]){
        island(field, visited, i - 1, j);
    } 
    if (!visited[i][j + 1]){
        island(field, visited, i, j + 1);
    }
    if (!visited[i][j - 1]){
        island(field, visited, i, j - 1);
    }
    return true;
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size() + 2, vector<int>(grid[0].size() + 2, 0)), field(grid.size() + 2, vector<int>(grid[0].size() + 2, 0));
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                field[i + 1][j + 1] = grid[i][j] - '0';
            }
        }
        int answer = 0;
        for (int i = 1; i <= grid.size(); i++){
            for (int j = 1; j <= grid[0].size(); j++){
                if (visited[i][j] == 0)
                    answer += island(field, visited, i, j);
            }
        }
        return answer;
    }
};
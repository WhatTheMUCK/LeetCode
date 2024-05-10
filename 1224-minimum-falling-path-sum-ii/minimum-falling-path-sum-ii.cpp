class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int min1, min2;
        for (int i = 1; i < grid.size(); i++){
            min1 = (~0u/2); min2 = (~0u/2);
            for (int j = 0; j < grid[i - 1].size(); j++){
                if (grid[i-1][j] < min1){
                    min2 = min1;
                    min1 = grid[i-1][j];
                } else if (grid[i -1][j] < min2){
                    min2 = grid[i-1][j];
                }
            }
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i-1][j] == min1){
                    grid[i][j] += min2;
                } else {
                    grid[i][j] += min1;
                }
            }
        }
        int answer = ~0u/2;
        for (int j = 0; j < grid.back().size(); j++){
            answer = min(answer, grid.back()[j]);
        }
        return answer;
    }
};
class Solution {
public:
    int maxIn3x3(int i, int j, vector<vector<int>>& grid){
        int maxIn3x3Ans = grid[i][j];
        for (int l = 0; l < 3; l++){
            for (int m = 0; m < 3; m++){
                maxIn3x3Ans = max(maxIn3x3Ans, grid[i + l][j + m]);
            }
        }
        return maxIn3x3Ans;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> answer(grid.size() - 2, vector<int>(grid[0].size() - 2, 0));
        for (int i = 0; i < grid.size() - 2; i++){
            for (int j = 0; j < grid[0].size() - 2; j++){
                answer[i][j] = maxIn3x3(i, j, grid);
            }
        }
        return answer;
    }
};
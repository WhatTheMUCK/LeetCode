class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeros;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == 0)
                    zeros.push_back({i, j});
            }
        }
        
        // for (int i = 0; i < zeros.size(); i++){
        //     cout << zeros[i][0] << " " << zeros[i][1] << "\n";
        // }

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (vector<int> zero : zeros){
            int x, y;
            for (int i = 0; i < directions.size(); i++){
                x = zero[1];
                y = zero[0];
                while (x >= 0 && x < matrix[0].size() && y >= 0 && y < matrix.size()){
                    matrix[y][x] = 0;
                    x += directions[i][1];
                    y += directions[i][0];
                }
            }
             
        }
    }
};
class Solution {
public:
    void IsLand(int i, int j, vector<vector<int>> &field, vector<vector<int>> &visited, vector<vector<int>> &answer){
        visited[i][j] = 1;
        if (field[i][j] == 1 && field[i + 1][j] == 0 && field[i][j + 1] == 0){
            answer.back().push_back(i - 1);
            answer.back().push_back(j - 1);
        }
        if (!visited[i + 1][j] && field[i + 1][j] == 1)
            IsLand(i + 1, j, field, visited, answer);
        if (!visited[i][j + 1]  && field[i][j + 1] == 1)
            IsLand(i, j + 1, field, visited, answer);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> field(land.size() + 2, vector<int>(land[0].size() + 2, 0));
        vector<vector<int>> visited = field, answer;
        for (int i = 0; i < land.size(); i++){
            for (int j = 0; j < land[0].size(); j++){
                field[i + 1][j + 1] = land[i][j] == 1;
            }
        }
        
        // for (int i = 0; i < field.size(); i++){
        //     for (int j = 0; j < field[0].size(); j++){
        //         cout << field[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        for (int i = 1; i <= land.size(); i++){
            for (int j = 1; j <= land[0].size(); j++){
                if (!visited[i][j] && field[i][j] == 1){
                    //cout << i << " " << j << "\n";
                    answer.push_back({i - 1, j - 1});
                    //cout << answer.back()[0] << " " << answer.back()[1] << "\n";
                    IsLand(i, j, field, visited, answer);
                }
            }
        }
        return answer;
    }
};
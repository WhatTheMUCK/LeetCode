class Solution {
public:
    int countPerimetr(vector<vector<int>> &map, vector<vector<int>> &visited, pair<int, int> pos){
        int i = pos.first;
        int j = pos.second;
        //cout << i << " " << j << "\n";

        if (map[i][j] == 0){
            return 1;
        }
        if (visited[i][j] == 1){
            return 0;
        }
        visited[i][j] = 1;
        return countPerimetr(map, visited, {i + 1, j}) + countPerimetr(map, visited, {i, j + 1}) + countPerimetr(map, visited, {i - 1, j}) + countPerimetr(map, visited, {i, j - 1});
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        pair<int, int> start;
        vector<vector<int>> map(grid.size() + 2, vector<int> (grid[0].size() + 2, 0)), visited(map.size(), vector<int>(map[0].size(), 0));
        for (int i = 1; i <= grid.size(); i++){
            for (int j = 1; j <= grid[0].size(); j++){
                map[i][j] = grid[i - 1][j - 1];
                if (map[i][j] == 1){
                    start = {i, j};
                }
                //cout << map[i][j] << " ";
            }
            //cout << "\n";
        }
        
        for (int i = 0; i < map.size(); i++){
            for (int j = 0; j < map[0].size(); j++){
                //cout << map[i][j] << " ";
            }
            //cout << "\n";
        }
        
        //cout << "start: " << start.first << " " << start.second << "\n";
        return countPerimetr(map, visited, start);

    }
};
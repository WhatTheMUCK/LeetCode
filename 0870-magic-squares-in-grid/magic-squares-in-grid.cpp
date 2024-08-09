class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int answer = 0;
        if (min(rows, cols) < 3)
            return answer;
        vector<int> sums(8, 0);
        set<int> numbers;
        bool exit;
        for (int i = 0; i <= rows - 3; i++){
            for (int j = 0; j <= cols - 3; j++){
                fill(sums.begin(), sums.end(), 0);
                numbers = {};
                exit = false;
                for (int k = 0; k < 3 * 3; k++){
                    int x = j + k % 3, y = i + k / 3;
                    int xOffset = k % 3, yOffset = k / 3;
                    if (!(1 <= grid[y][x] && grid[y][x] <= 9)){
                        exit = true;
                        break;
                    }
                    sums[yOffset] += grid[y][x]; // Первые 3 позиции (0, 1, 2) отведены под строки
                    sums[xOffset + 3] += grid[y][x]; // 3, 4, 5 отведены под столцы
                    if (xOffset == yOffset)
                        sums[6] += grid[y][x]; // 6 - главная диагональ
                    if (xOffset + yOffset == 2)
                        sums[7] += grid[y][x]; // 7 - побочная диагональ
                    numbers.insert(grid[y][x]);
                }
                if (!exit && numbers.size() == 9){
                    set<int> checker(sums.begin(), sums.end());
                    answer += checker.size() == 1;
                }       

            }
        }
        return answer;
    }
};
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;  // индекс текущего направления
        int steps = 1;  // количество шагов в текущем направлении

        result.push_back({rStart, cStart});
        int totalCells = rows * cols;

        while (result.size() < totalCells) {
            for (int i = 0; i < 2; ++i) {  // увеличиваем шаги каждые два поворота
                for (int j = 0; j < steps; ++j) {
                    rStart += directions[d][0];
                    cStart += directions[d][1];
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        result.push_back({rStart, cStart});
                    }
                }
                d = (d + 1) % 4;  // переходим к следующему направлению
            }
            steps++;  // увеличиваем количество шагов
        }

        return result;
    }
};
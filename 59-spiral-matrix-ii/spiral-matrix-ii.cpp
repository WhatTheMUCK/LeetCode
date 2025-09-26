std::pair<int, int> & operator+=(std::pair<int, int> & lhs, const std::pair<int, int> & rhs) {
    lhs.first += rhs.first;
    lhs.second += rhs.second;
    return lhs;
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::pair<int, int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        std::vector<std::vector<int>> answer(n, std::vector<int>(n));
        int curValue = 1;
        int helper = 2 * n;
        std::pair<int, int> curPos = {0, -1};
        while (curValue <= n * n) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < (helper / 2); ++j) {
                    if (curValue > n * n) {
                        return answer;
                    }
                    curPos += offsets[i];
                    auto & [row, col] = curPos;
                    answer[row][col] = curValue++;
                }
                --helper;
            }
        }

        return answer;
    }
};
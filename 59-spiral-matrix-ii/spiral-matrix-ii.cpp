class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> generateMatrix(int n) {
        int helper = 1, counter = n * n, steps, i = 0, j = -1;
        vector<vector<int>> answer(n, vector<int>(n));
        while (counter){
            for (int k = 0; k < 4; k++){
                steps = n - (helper / 2);
                while (counter && steps){
                    i += directions[k][0];
                    j += directions[k][1];
                    steps--;
                    counter--;
                    answer[i][j] = n * n - counter;
                }
                helper++;
            }
        }
        return answer;
    }
};
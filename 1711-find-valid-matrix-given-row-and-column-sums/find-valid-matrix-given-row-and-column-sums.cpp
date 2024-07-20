class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        long long prevColSum = 0, excess = 0;
        for (int i = 0; i < n; i++){
            matrix[i][0] = rowSum[i];
            prevColSum += rowSum[i];
        }
        for (int j = 0; j < m - 1; j++){
            excess = prevColSum - colSum[j];
            prevColSum = excess;
            for (int i = 0; i < n && excess > 0; i++){
                int move = min(1ll * matrix[i][j], excess);
                matrix[i][j] -= move;
                matrix[i][j + 1] += move;
                excess -= move;
            }
        }

        return matrix;

        
    }
};
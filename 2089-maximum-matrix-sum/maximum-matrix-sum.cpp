class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int maxNegative = 1e9;
        long long sumMatrix = 0;
        int negativeCount = 0;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                sumMatrix += abs(matrix[i][j]);
                maxNegative = min(maxNegative, abs(matrix[i][j]));
                if (matrix[i][j] < 0)
                    negativeCount++;
            }
        }
        if (negativeCount % 2 == 1){
            sumMatrix -= 2 * maxNegative;
        }
        return sumMatrix;
    }
};
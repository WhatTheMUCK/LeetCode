class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> answer(m, vector<int>(n));
        int size = original.size();
        if (size != m * n)
            return {};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                answer[i][j] = original[i * n + j];
            }
        }
        return answer;
    }
};
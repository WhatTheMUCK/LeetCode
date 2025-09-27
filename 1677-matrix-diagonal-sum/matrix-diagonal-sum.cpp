class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int answer = 0;
        for (size_t i = 0; i < mat.size(); ++i) {
            answer += mat[i][i] + mat[i][mat.size() - (i + 1)];
            if (i == mat.size() - (i + 1)) {
                answer -= mat[i][mat.size() - (i + 1)];
            }
        }
        return answer;
    }
};
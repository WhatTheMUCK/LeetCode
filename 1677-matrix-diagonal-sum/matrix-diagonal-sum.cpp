class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int answer = 0;
        int n = mat.size();
        int i = 0, j = 0;
        while (i < n && j < n){
            answer += mat[i][j++];
            answer += mat[i++][n - j];
        }
        if (n % 2)
            answer -= mat[n / 2][n / 2];
        return answer;
    }
};
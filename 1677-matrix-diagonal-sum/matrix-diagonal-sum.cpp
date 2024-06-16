class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int answer = 0;
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = 0;
        while (i < n && j < m){
            answer += mat[i++][j++];
        }
        i = 0, j = m - 1;
        while (i < n && j >= 0){
            answer += mat[i++][j--];
        }
        if (n * m % 2)
            answer -= mat[n / 2][m / 2];
        return answer;
    }
};
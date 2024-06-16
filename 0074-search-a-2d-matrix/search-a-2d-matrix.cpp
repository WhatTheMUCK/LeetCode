class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n * m - 1, median;
        int i, j;
        while (l <= r){
            median = (l + r) / 2;
            i = median / m;
            j = median % m;
            if (target == matrix[i][j])
                return true;
            if (target < matrix[i][j]){
                r = median - 1;
            } else {
                l = median + 1;
            }
        }
        return false;
    }
};
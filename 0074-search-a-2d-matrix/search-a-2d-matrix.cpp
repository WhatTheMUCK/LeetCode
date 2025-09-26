class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        if (n * m == 0) {
            return false;
        }
        int l = 0, r = n * m - 1;
        int row, col;
        while (l < r) {
            int mid = (l + r) / 2;
            row = mid / m;
            col = mid % m;
            if (matrix[row][col] == target) {
                return true;
            } 

            if (matrix[row][col] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        row = l / m;
        col = l % m;

        return matrix[row][col] == target;
    }
};
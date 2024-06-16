class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> column0;
        generate_n(back_inserter(column0), matrix.size(), [i = 0, &matrix]() mutable { return matrix[i++][0]; });
        int row = (upper_bound(column0.begin(), column0.end(), target) - column0.begin()) - 1; //upper ищет первый элемент строго больше
        if (row == -1)
            return false;
        int col = lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
        if (col == matrix[row].size() || matrix[row][col] != target)
            return false;
        return true;
    }
};
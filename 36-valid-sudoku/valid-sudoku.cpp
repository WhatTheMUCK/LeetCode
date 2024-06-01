class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> check(10, 0);
        for (int i = 0; i < board.size(); i++){
            check.assign(check.size(), 0);
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] != '.'){
                    if (check[board[i][j] - '0'])
                        return false;
                    check[board[i][j] - '0']++;
                }
            }
        }

        for (int j = 0; j < board[0].size(); j++){
            check.assign(check.size(), 0);
            for (int i = 0; i < board.size(); i++){
                if (board[i][j] != '.'){
                    if (check[board[i][j] - '0'])
                        return false;
                    check[board[i][j] - '0']++;
                }
            }
        }
        int step = 0;
        while (step < 9){
            int upCheckBox = (step / 3) * 3, leftCheckBox = (step % 3) * 3, downCheckBox = ((step / 3) + 1) * 3, rightCheckBox = ((step % 3) + 1) * 3;
            check.assign(check.size(), 0);
            for (int i = upCheckBox; i < downCheckBox; i++){
                for (int j = leftCheckBox; j < rightCheckBox; j++){
                    if (board[i][j] != '.'){
                        if (check[board[i][j] - '0'])
                            return false;
                        check[board[i][j] - '0']++;
                    }
                }
            }
            step++;
        }
        return true;
    }
};
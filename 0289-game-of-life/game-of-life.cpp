class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                count = 0;
                for (int I = max(i - 1, 0); I < min(i + 2, n); I++){
                    for (int J = max(j - 1, 0); J < min(j + 2, m); J++){
                        count += board[I][J] & 1;
                    }
                }
                if (count == 3 || board[i][j] == 1 && count == 4)
                    board[i][j] |= 2;
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                board[i][j] >>= 1;
            }
        }

        return;
    }
};
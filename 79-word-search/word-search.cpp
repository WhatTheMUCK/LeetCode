class Solution {
public:

    bool dfs(int i, int j, int amount, vector<vector<char>>& board, string &word, vector<vector<int>>& visited){
        visited[i][j] = 1;
        if (amount == word.size())
            return true;
        bool flag = false;
        if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[amount]){
            flag |= dfs(i, j - 1, amount + 1, board, word, visited);
        }
        if (j < board[0].size() - 1 && !visited[i][j + 1] && board[i][j + 1] == word[amount]){
            flag |= dfs(i, j + 1, amount + 1, board, word, visited);
        }
        if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[amount]){
            flag |= dfs(i - 1, j, amount + 1, board, word, visited);
        }
        if (i < board.size() - 1 && !visited[i + 1][j] && board[i + 1][j] == word[amount]){
            flag |= dfs(i  + 1, j, amount + 1, board, word, visited);
        }
        visited[i][j] = 0;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    if (dfs(i, j, 1, board, word, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
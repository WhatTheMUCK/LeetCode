class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        string conditions = "rdlu";
        int pos = 0;
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> answer;
        int check = matrix.size() * matrix[0].size() - 1;
        int i = 0, j = 0;
        while (check > 0){
            visited[i][j] = 0;
            check++;
            while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && visited[i][j] == 0){
                cout << i << " " << j << "\n";
                visited[i][j] = 1;
                answer.push_back(matrix[i][j]);
                i += direction[pos][0];
                j += direction[pos][1];
                check--;
            }
            i -= direction[pos][0];
            j -= direction[pos][1];
            visited[i][j]--;
            answer.pop_back();
            pos = (pos + 1) % conditions.size();
        }
        answer.push_back(matrix[i][j]);
        return answer;
    }
};
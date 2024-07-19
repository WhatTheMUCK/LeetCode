class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int, int>> minInRow(n, {1e6, -1}), maxInCol(m, {0, -1});
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (minInRow[i].first > matrix[i][j])
                    minInRow[i] = {matrix[i][j], j};
                if (maxInCol[j].first < matrix[i][j])
                    maxInCol[j] = {matrix[i][j], i};
            }
        }
        
        vector<int> answer;
        for (int i = 0; i < n; i++){
            int minPos = minInRow[i].second;
            if (maxInCol[minPos].second == i)
                answer.push_back(minInRow[i].first);
        }

        return answer;
    }
};
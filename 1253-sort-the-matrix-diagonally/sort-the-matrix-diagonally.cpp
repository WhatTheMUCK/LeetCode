class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> answer = mat;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < mat.size(); i++){
            for (int j = 0; j < mat[i].size(); j++){
                mp[i - j].push_back(mat[i][j]);
            }
        }

        unordered_map<int, vector<int>>::iterator iter = mp.begin();
        while (iter != mp.end()){
            sort((*iter).second.rbegin(), (*iter).second.rend());
            iter++;
        }

        for (int i = 0; i < mat.size(); i++){
            for (int j = 0; j < mat[i].size(); j++){
                answer[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return answer;
    }
};
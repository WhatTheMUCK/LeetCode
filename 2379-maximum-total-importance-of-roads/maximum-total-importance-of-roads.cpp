class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cityUsage(n, 0);
        for (vector<int> &elem : roads){
            cityUsage[elem[0]]++;
            cityUsage[elem[1]]++;
        }
        sort(cityUsage.begin(), cityUsage.end());
        long long answer = 0;
        for (int i = 0; i < n; i++){
            answer += 1ll * (i + 1) * cityUsage[i];
        }
        return answer;
    }
};
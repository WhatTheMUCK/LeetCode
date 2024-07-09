class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long sum = 0;
        long long time = 0;
        for (int i = 0; i < n; i++){
            time = max(time, 1ll * customers[i][0]);
            time += customers[i][1];
            sum += time - customers[i][0];
        }
        return (double) sum / n;
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        vector<pair<int, int>> helper;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            helper.push_back({nums[i], i});
        }
        sort(helper.begin(), helper.end());
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++){
            int index = helper[i].second;
            if (visited[index]){
                continue;
            }

            score += helper[i].first;
            visited[index] = 1;
            if (index > 0){
                visited[index - 1] = 1;
            }
            if (index < n - 1){
                visited[index + 1] = 1;
            }
        }

        return score;
    }
};
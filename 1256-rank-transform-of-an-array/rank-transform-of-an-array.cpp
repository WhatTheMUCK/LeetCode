class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return arr;
        vector<pair<int, int>> helper(n);
        for (int i = 0; i < n; i++){
            helper[i] = {arr[i], i};
        }
        sort(helper.begin(), helper.end());
        int rank = 1;
        arr[helper[0].second] = rank;
        for (int i = 1; i < n; i++){
            if (helper[i].first > helper[i - 1].first)
                rank++;
            arr[helper[i].second] = rank;
        }
        return arr;
    }
};
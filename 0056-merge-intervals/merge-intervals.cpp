class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        int l1 = intervals[0][0], r1 = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            int l2 = intervals[i][0], r2 = intervals[i][1];
            if (l2 > r1){
                answer.push_back({l1, r1});
                l1 = l2;
                r1 = r2;
            } else {
                l1 = min(l1, l2);
                r1 = max(r1, r2);
            }
        }
        answer.push_back({l1, r1});
        return answer;
    }
};
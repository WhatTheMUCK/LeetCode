class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &lhs, vector<int> &rhs){
            if (lhs[1] == rhs[1])
                return lhs[0] < rhs[0];
            return lhs[1] < rhs[1];
        });
        int arrows = 1;
        int x = points[0][1];
        int i = 0, n = points.size();
        while (true){
            for (i; i < n && points[i][0] <= x; i++);
            if (i == n)
                break;
            arrows++;
            x = points[i][1];
        }
        return arrows;
    }
};
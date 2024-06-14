class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> answer;
        int l, r, i1 = 0, i2 = 0;
        while (i1 < firstList.size() && i2 < secondList.size()){
            l = max(firstList[i1][0], secondList[i2][0]);
            r = min(firstList[i1][1], secondList[i2][1]);
            if (l <= r){
                answer.push_back({l, r});
            }
            if (firstList[i1][1] > secondList[i2][1])
                i2++;
            else
                i1++;
        }
        return answer;
    }
};
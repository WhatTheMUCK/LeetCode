class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int answer = 0;
        int minVal = arrays[0][0], maxVal = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++){
            int tempMin = arrays[i][0], tempMax = arrays[i].back();
            answer = max({answer, abs(maxVal - tempMin), abs(minVal - tempMax)});
            minVal = min(minVal, tempMin);
            maxVal = max(maxVal, tempMax);
        }
        return answer;
    }
};
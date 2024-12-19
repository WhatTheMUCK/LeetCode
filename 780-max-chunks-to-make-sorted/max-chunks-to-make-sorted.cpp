class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int curStart = 0, curSum = 0, tempSum = 0, curDigit = 0;
        int i = 0, answer = 0;
        while (i < n){
            bool findCurStart = false;
            while (!findCurStart || curSum != tempSum){
                if (arr[i] == curStart){
                    findCurStart = true;
                }
                curSum += curDigit++;
                tempSum += arr[i++];
            }
            curStart = curDigit, curSum = 0, tempSum = 0;
            answer++;
        }
        return answer;
    }
};
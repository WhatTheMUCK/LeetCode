class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        return accumulate(endTime.begin(), endTime.end(), 0, [i = 0, &startTime, &queryTime](int acc, int x) mutable {
            return acc + (startTime[i++] <= queryTime && queryTime <= x);
        });
    }
};
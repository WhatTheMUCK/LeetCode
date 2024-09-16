class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int, int>> times;
        for (string timePoint : timePoints){
            stringstream ss(timePoint);
            int hour, minute;
            char colon;
            ss >> hour >> colon >> minute;
            // cout << hour << " " << minute << "\n";
            times.push_back({hour, minute});
        }
        sort(times.begin(), times.end());
        int n = times.size();
        int answer = (times[0].first + (23 - times[n - 1].first)) * 60 + (times[0].second + (60 - times[n - 1].second));
        for (int i = 1; i < n; i++){
            int newTime = (times[i].first - times[i - 1].first) * 60 + (times[i].second - times[i - 1].second);
            answer = min(answer, newTime);
        }
        return answer;
    }
};
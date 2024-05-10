class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp('z' - 'a' + 1, 0);
        for (int i = 0; i < s.size(); i++){
            int ind = s[i] - 'a';
            int left = max(ind - k, 0);
            int right = min(ind + k, (int)dp.size() - 1);
            for (int j = left; j <= right; j++){
                dp[ind] = max(dp[j], dp[ind]);
            }
            dp[ind]++;
        }
        
        int answer = 0;
        for (int i = 0; i < dp.size(); i++){
            //cout << (char)('a' + i) << ": " << dp[i] << "\n";
            answer = max(answer, dp[i]);
        }
        
        return answer;
    }
};
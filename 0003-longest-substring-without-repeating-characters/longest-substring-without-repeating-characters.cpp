class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(128, 0);
        int l = 0, answer = 0;
        for (int r = 0; r < s.size(); r++){
            dict[s[r]]++;
            while (dict[s[r]] > 1)
                dict[s[l++]]--;
            answer = max(answer, r - l + 1);
        }
        return answer;
    }
};
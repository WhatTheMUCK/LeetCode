class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(128, 0);
        int l = 0, r = 0;
        int answer = 0;
        while (r < s.size()){
            dict[s[r]]++;
            while (dict[s[r]] > 1){
                dict[s[l]]--;
                l++;
            }
            answer = max(answer, r - l + 1);
            r++;
        }
        return answer;
    }
};
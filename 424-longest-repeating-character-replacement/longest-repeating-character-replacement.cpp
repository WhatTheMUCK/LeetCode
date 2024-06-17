class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, maxf = 0, answer = 0;
        for (r; r < s.size(); r++){
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);

            if (r - l + 1 - maxf > k){
                mp[s[l++]]--;
            } else {
                answer = max(answer, r - l + 1);
            }
        }
        return answer;
    }
};
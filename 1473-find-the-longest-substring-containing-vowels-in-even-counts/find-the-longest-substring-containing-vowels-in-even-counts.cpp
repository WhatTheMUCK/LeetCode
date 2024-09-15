class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels = "aeiou";
        int n = s.size();
        unordered_map<int, int> bitMasks = {{0, -1}};
        int bitMask = 0;
        int answer = 0;
        for (int i = 0; i < n; i++){
            int search = vowels.find(s[i]);
            if (search != -1){
                bitMask ^= 1 << search;
            }
            if (bitMasks.contains(bitMask)){
                answer = max(answer, i - bitMasks[bitMask]);
            } else {
                bitMasks[bitMask] = i;
            }
        }
        return answer;
    }
};
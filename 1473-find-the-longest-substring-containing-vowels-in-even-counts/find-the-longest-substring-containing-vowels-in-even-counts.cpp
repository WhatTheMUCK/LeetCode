class Solution {
public:
    int findTheLongestSubstring(string s) {
        string vowels = "aeiou";
        int n = s.size();
        vector<int> store(n, 0);
        int bitMask = 0;
        for (int i = 0; i < n; i++){
            int search = vowels.find(s[i]);
            if (search != -1){
                bitMask ^= 1 << search;
            }
            store[i] = bitMask;
        }
        unordered_map<int, int> bitMasks = {{0, -1}};
        int answer = 0;
        for (int i = 0; i < n; i++){
            if (bitMasks.contains(store[i])){
                answer = max(answer, i - bitMasks[store[i]]);
            } else {
                bitMasks[store[i]] = i;
            }
        }
        return answer;
    }
};
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int bitMask = 0;
        for (char letter : allowed){
            bitMask |= 1 << (letter - 'a');
        }
        int answer = 0, tempBitMask;
        for (string word : words){
            tempBitMask = 0;
            for (char letter : word){
                tempBitMask |= 1 << (letter - 'a');
            }
            answer += tempBitMask == (tempBitMask & bitMask);
        }
        return answer;
    }
};
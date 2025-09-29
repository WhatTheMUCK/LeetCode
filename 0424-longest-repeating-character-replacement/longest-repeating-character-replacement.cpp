class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = static_cast<int>(s.size());
        
        int answer = 0;
        string dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (char letter : dictionary) {
            int tempK = k;
            int l = 0, r = 0;
            while (r < n) {
                answer = max(answer, r - l);
                if (s[r] != letter) {
                    if (tempK > 0) {
                        --tempK;
                        ++r;
                        continue;
                    } else {
                        tempK += s[l] != letter;
                        ++l;
                        continue; 
                    }
                }
                ++r;
            }
            answer = max(answer, r - l);
        }

        return answer;
    }
};
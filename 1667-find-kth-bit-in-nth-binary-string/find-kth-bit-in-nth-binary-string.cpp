class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while (s.size() < k){
            int ind = s.size() - 1;
            s.push_back('1');
            for (ind; ind >= 0; ind--)
                s.push_back(('1' - s[ind]) + '0');
        }
        return s[k - 1];
    }
};
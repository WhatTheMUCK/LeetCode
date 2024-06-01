class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> letter('z' - 'a' + 1, INT_MAX);
        for (int i = 0; i < s.size(); i++){
            if (letter[s[i] - 'a'] == INT_MAX)
                letter[s[i] - 'a'] = i;
            else if (letter[s[i] - 'a'] != INT_MAX - 1){
                letter[s[i] - 'a'] = INT_MAX - 1;
            }
        }
        int minInd = *min_element(letter.begin(), letter.end());
        if (minInd < INT_MAX - 1)
            return minInd;
        return -1;
    }
};
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), m = spaces.size();
        string answer(n + m, ' ');
        int spaceInd = 0;
        for (int i = 0; i < n; i++){
            if (spaceInd < m && i == spaces[spaceInd]){
                spaceInd++;
            }
            answer[i + spaceInd] = s[i];
        }
        return answer;
    }
};
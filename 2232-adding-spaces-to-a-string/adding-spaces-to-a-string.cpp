class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer = "";
        int n = s.size(), m = spaces.size();
        int spaceInd = 0;
        for (int i = 0; i < n; i++){
            if (spaceInd < m && i == spaces[spaceInd]){
                answer.push_back(' ');
                spaceInd++;
            }
            answer.push_back(s[i]);
        }
        return answer;
    }
};
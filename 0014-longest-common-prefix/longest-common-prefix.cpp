class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = strs[0];
        for (int i = 1; i < strs.size(); i++){
            if (strs[i].size() < answer.size()){
                answer = answer.substr(0, strs[i].size());
            } 
            for (int j = 0; j < answer.size(); j++){
                if (answer[j] != strs[i][j]){
                    if (j > 0){
                        answer = answer.substr(0, j);
                    } else {
                        answer = "";
                    }
                    break;
                }
            }
        }
        return answer;
    }
};
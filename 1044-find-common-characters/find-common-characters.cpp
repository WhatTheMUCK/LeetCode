class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> helper(words.size(), vector<int>('z' - 'a' + 1, 0));
        for (int i = 0; i < words.size(); i++){
            for (char elem : words[i]){
                helper[i][elem - 'a']++;
            }
        }
        vector<int> counting = helper[0];
        for (int  i = 1; i < helper.size(); i++){
            for (int j = 0; j < 'z' - 'a' + 1; j++){
                counting[j] = min(counting[j], helper[i][j]);
            }
        }
        vector<string> answer;
        for (int i = 0; i < 'z' - 'a' + 1; i++){
            generate_n(back_inserter(answer), counting[i], [&i](){ return string(1, 'a' + i); });
        }
        return answer;
    }
};
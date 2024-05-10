class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string line = "", tempSpace = "";
        vector<string> answer, temp;
        int chars = 0, cur = 0, spaces = 0;
        while (cur < words.size()){
            line = "";
            temp = {};
            chars = words[cur].size();
            spaces = 0;
            temp.push_back(words[cur]);
            cur++;
            while (cur < words.size() && chars + words[cur].size() + 1 <= maxWidth){
                chars += words[cur].size() + 1;
                spaces++;
                temp.push_back(words[cur]);
                cur++;
            }
            if (cur < words.size()){
                //cout << "*\n";
                spaces = maxWidth - (chars - spaces);
                chars = 0;
                for (int i = temp.size() - 1; i >= 0; i--){
                    tempSpace = "";
                    if (i > 0){
                        for (int j = 0; j < spaces / i; j++){
                            tempSpace += " ";
                        }
                        spaces -= spaces / i;
                    }
                    line = tempSpace + temp[i] + line;
                    chars += tempSpace.size() + temp[i].size();
                }
                for (int i = chars; i < maxWidth; i++){
                    line += " ";
                }
                answer.push_back(line);
            } else {
                chars = 0;
                for (int i = 0; i < temp.size(); i++){
                    line += temp[i] + " ";
                    chars += temp[i].size() + 1;
                }
                line.pop_back();
                chars--;
                for (int i = chars; i < maxWidth; i++){
                    line += " ";
                }
                answer.push_back(line);
            }
        }
        return answer;
    }
};
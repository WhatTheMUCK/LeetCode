class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string answer = "";
        unordered_set<string> dict;
        for (string &elem : dictionary){
            dict.insert(elem);
        }
        stringstream ss(sentence);
        string temp, search;
        while (ss >> temp){
            search = "";
            for (int i = 0; i < temp.size() && !dict.contains(search); i++){
                search.push_back(temp[i]);
            }
            answer += search + " ";
        }
        answer.pop_back();
        return answer;
    }
};
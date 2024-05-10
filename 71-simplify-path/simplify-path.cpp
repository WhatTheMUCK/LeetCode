class Solution {
public:
    string simplifyPath(string path) {
        vector<string> helper;
        string temp = "";
        path += '/';
        for (char elem : path){
            if (elem == '/'){
                if (temp == ".."){
                    if (!helper.empty())
                        helper.pop_back();
                } else if (temp != "." && !temp.empty()){
                    helper.push_back(temp);
                }
                temp = "";
            } else {
                temp += elem;
            }
        }
        string answer = "/";
        for (string elem : helper){
            answer += elem + "/";
        }
        if (answer.size() > 1)
            answer.pop_back();
        return answer;
    }
};
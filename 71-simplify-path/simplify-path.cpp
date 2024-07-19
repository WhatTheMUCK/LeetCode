class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        deque<string> dirs;
        string directory = "";
        unordered_set<string> skip = {
            "",
            ".",
            ".."
        };
        for (char elem : path){
            if (elem == '/'){
                if (directory == ".." && !dirs.empty()){
                    dirs.pop_back();
                } else if (!skip.contains(directory)){
                    dirs.push_back(directory);
                }
                directory = "";
            } else {
                directory.push_back(elem);
            }
        }

        string answer = "";
        while (!dirs.empty()){
            answer += "/" + dirs.front();
            dirs.pop_front();
        }

        return (answer.empty() ? "/" : answer);
    }
};
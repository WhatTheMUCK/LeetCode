#include <vector>

class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        std::vector<std::string> helper;
        int prevSlash = path.find('/');
        int curSlash;
        while ((curSlash = path.find('/', prevSlash + 1)) != std::string::npos) {
            std::string word = path.substr(prevSlash + 1, curSlash - prevSlash - 1);
            prevSlash = curSlash;
            if (word == "." || word.empty()) {
                continue;
            }

            if (word == "..") {
                if (!helper.empty()){
                    helper.pop_back();
                }
                continue;
            }

            helper.push_back(word);
        }

        std::string answer;
        if (helper.empty()) {
            helper.push_back("");
        }
        
        for (const std::string & word : helper) {
            answer += '/' + word;
        }
        return answer;
    }
};
class Solution {
public:
    int countSeniors(vector<string>& details) {
        return count_if(details.begin(), details.end(), [](string& info){ return stoi(info.substr(11, 2)) > 60; });
    }
};
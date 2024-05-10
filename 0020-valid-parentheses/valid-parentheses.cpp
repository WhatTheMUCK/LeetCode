class Solution {
public:
    bool isValid(string s) {
        vector<int> parenthesis;
        string straight = "([{", reverse = ")]}";
        string::iterator search;
        for (char elem : s){
            search = find(straight.begin(), straight.end(), elem);
            if (search != straight.end()){
                parenthesis.push_back(reverse[search - straight.begin()]);
            } else {
                if (parenthesis.empty() || parenthesis.back() != elem)
                    return false;
                parenthesis.pop_back();
            }
        }
        return parenthesis.empty();
    }
};
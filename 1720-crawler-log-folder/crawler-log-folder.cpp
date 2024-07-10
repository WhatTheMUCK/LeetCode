class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> path;
        for (string folder : logs){
            folder.pop_back();
            if (folder == ".." && !path.empty()){
                path.pop();
            } else if (folder != "." && folder != ".."){
                path.push(folder);
            }
        }
        return path.size();
    }
};
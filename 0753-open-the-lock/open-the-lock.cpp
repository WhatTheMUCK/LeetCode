class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        for (string elem : deadends){
            visited.insert(elem);
        }
        queue<pair<string, int>> layer;
        if (visited.find("0000") != visited.end()){
            return -1;
        }
        layer.push({"0000", 0});
        visited.insert("0000");
        while (!layer.empty()){
            pair<string, int> current = layer.front();
            layer.pop();
            if (current.first == target){
                return current.second;
            }
            for (int i = 0; i < current.first.size(); i++){
                string helper = current.first;
                char elem1 = (current.first[i] - '0' + 1) % 10 + '0';
                char elem2 = (current.first[i] - '0' + 10 - 1) % 10 + '0';
                helper[i] = elem1;
                if (visited.find(helper) == visited.end()){
                    visited.insert(helper);
                    layer.push({helper, current.second + 1});
                }
                helper[i] = elem2;
                if (visited.find(helper) == visited.end()){
                    visited.insert(helper);
                    layer.push({helper, current.second + 1});
                }
            }
        }
        return -1;
    }
};
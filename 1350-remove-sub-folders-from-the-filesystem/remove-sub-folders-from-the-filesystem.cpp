class Solution {
public:

    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folders;
        vector<string> answer;
        sort(folder.begin(), folder.end(), [](string &lhs, string &rhs){ return lhs.size() < rhs.size(); });
        for (string &elem : folder){
            bool exist = false;
            string temp = elem;
            int i = elem.size() - 1;
            while (i >= 0){
                exist |= folders.contains(temp);
                for (i; elem[i] != '/'; i--)
                    temp.pop_back();
                i--;
                temp.pop_back();
            }
            if (!exist){
                answer.push_back(elem);
                folders.insert(elem);
            }
        }
        return answer;
    }
};
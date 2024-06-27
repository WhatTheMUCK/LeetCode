class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> node;
        int n = edges.size();
        for (vector<int> elem : edges){
            node[elem[0]]++;
            node[elem[1]]++;
            if (node[elem[0]] == n)
                return elem[0];
            if (node[elem[1]] == n)
                return elem[1];
        }
        return -1;

    }
};
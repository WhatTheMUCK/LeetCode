class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1){
            return {0};
        }
        unordered_map<int, vector<int>> adjacents;
        vector<int> degree(n, 0);
        for (vector<int> elem : edges){
            adjacents[elem[0]].push_back(elem[1]);
            adjacents[elem[1]].push_back(elem[0]);
            degree[elem[0]]++;
            degree[elem[1]]++;
        }
        
        queue<int> leaves;
        for (int i = 0; i < n; i++){
            if (degree[i] == 1)
                leaves.push(i);
        }

        int remainingNodes = n;
        while (remainingNodes > 2){
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;
            for (int i =  0; i < leavesCount; i++){
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbour : adjacents[leaf]){
                    if (--degree[neighbour] == 1)
                        leaves.push(neighbour);
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()){
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};
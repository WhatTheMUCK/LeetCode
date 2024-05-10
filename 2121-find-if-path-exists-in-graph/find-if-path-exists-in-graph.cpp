class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_set<int> visited;
        unordered_map<int, vector<int>> adjacent;
        for (int i = 0; i < edges.size(); i++){
            adjacent[edges[i][0]].push_back(edges[i][1]);
            adjacent[edges[i][1]].push_back(edges[i][0]);
        }
        deque<int> order = {source};
        int current;
        while (!order.empty()){
            current = order.front();
            order.pop_front();
            if (visited.find(current) != visited.end()){
                continue;
            }
            if (current == destination)
                return true;
            visited.insert(current);
            for(int elem : adjacent[current]){
                if (visited.find(elem) == visited.end())
                    order.push_back(elem);
            } 
        }
        return false;
    }
};
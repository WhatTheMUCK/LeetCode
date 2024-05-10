class Solution {
public:
    int findRotateSteps(string ring, string key) {
        queue<vector<int>> search, tempSearch;
        unordered_map<char, vector<int>> dict;
        for (int i = 0; i < ring.size(); i++){
            dict[ring[i]].push_back(i);
        }
        // for (pair<char, vector<int>> elem : dict){
        //     cout << elem.first << ": ";
        //     for (int elemInner : elem.second){
        //         cout << elemInner << " ";
        //     }
        //     cout << "\n";
        // }
        search.push({0, 0});
        vector<vector<int>> dp(key.size(), vector<int>(ring.size(), -1));
        int curpos, cost, newCost;
        vector<int> temp;
        for (int i = 0; i < key.size(); i++){
            while (!search.empty()){
                curpos = search.front()[0];
                cost = search.front()[1];
                search.pop();
                temp = {};
                for (int index : dict[key[i]]){
                    newCost = cost + min(abs(curpos - index), (int)ring.size() - abs(curpos - index)) + 1;
                    temp = {index, newCost};
                    if (dp[i][index] == -1 || dp[i][index] > newCost){
                        tempSearch.push(temp);
                        dp[i][index] = newCost;
                    }
                } 
            }
            search = tempSearch;
            tempSearch = {};
        }   
        int answer = (~0u/2);
        for (int i = 0; i < dp.back().size(); i++){
            if (dp.back()[i] != -1)
                answer = min(answer, dp.back()[i]);
        }
        return answer;
    }
};
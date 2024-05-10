class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        int maximum = -1;
        for (int elem : nums){
            if (dict.find(elem) != dict.end()){
                dict[elem]++;
            } else {
                dict[elem] = 1;
            }
            maximum = max(maximum, dict[elem]);
        }

        vector<vector<int>> helper(1e5);
        for (pair<int, int> elem : dict){
            helper[elem.second - 1].push_back(elem.first);
        }

        vector<int> answer;
        for (int i = maximum; i >= 0 && k > 0; i--){
            if (!helper[i].empty()){
                for (int j = 0; j < helper[i].size() && k > 0; j++){
                    answer.push_back(helper[i][j]);
                    k--;
                }
            }
        }
        return answer;
    }
};
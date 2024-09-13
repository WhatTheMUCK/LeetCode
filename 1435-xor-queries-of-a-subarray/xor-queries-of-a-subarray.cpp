class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n + 1, 0);

        for (int i = 1; i < n + 1; i++){
            prefixXor[i] = prefixXor[i - 1] ^ arr[i - 1];
        }
        vector<int> answer;
        for (vector<int> query : queries){
            answer.push_back(prefixXor[query[1] + 1] ^ prefixXor[query[0]]);
        }
        return answer;
    }
};
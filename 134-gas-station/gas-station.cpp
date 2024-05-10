class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = -1, sumfuel = 0, maxSum = -1;;
        for (int i = (int)gas.size() - 1; i >= 0; i--){
            sumfuel += gas[i] - cost[i];
            if (sumfuel > maxSum){
                start = i;
                maxSum = sumfuel;
            }
        }
        if (sumfuel < 0){
            start = -1;
        }
        return start;
    }
};
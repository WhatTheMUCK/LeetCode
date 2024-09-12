class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int restSum = (n + m) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (restSum < n || restSum > 6 * n)
            return {}; 
        vector<int> answer(n, 1);
        restSum -= n;
        for (int i = 0; i < n && restSum > 0; i++){
            int newValue = min(6, restSum + 1);
            answer[i] = newValue;
            restSum -= newValue - 1; 
        }
        return answer;
    }
};
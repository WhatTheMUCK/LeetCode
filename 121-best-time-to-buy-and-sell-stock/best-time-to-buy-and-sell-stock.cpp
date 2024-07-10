class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], answer = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < buy)
                buy = prices[i];
            answer = max(answer, prices[i] - buy);
        }
        return answer;
    }
};
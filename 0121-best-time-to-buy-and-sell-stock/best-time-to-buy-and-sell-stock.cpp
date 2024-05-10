class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 0, benefit = 0;
        while(sell < prices.size()){
            benefit = max(benefit, prices[sell] - prices[buy]);
            if (prices[sell] < prices[buy])
                buy = sell;
            sell++;
        }
        return benefit;
    }
};
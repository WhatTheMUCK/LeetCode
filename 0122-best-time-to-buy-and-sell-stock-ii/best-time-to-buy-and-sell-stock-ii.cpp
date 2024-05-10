class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, maxTempProfit = 0;
        int l = 0, r = 1;
        while (r < prices.size()){
            if (prices[r - 1] < prices[r]){
                profit += prices[r] - prices[r - 1];
            } 
            r++;
        }
        return profit;
    }
};
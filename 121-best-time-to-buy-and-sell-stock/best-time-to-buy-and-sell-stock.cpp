class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int minValue = prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            answer = std::max(answer, prices[i] - minValue);
            minValue = std::min(minValue, prices[i]);
        }
        return answer;
    }
};
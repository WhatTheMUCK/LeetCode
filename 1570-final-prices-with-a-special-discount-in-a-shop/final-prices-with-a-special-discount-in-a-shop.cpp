class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer(n);
        for (int i = 0; i < n; i++){
            int discount = 0;
            int j = i + 1;
            for (j; j < n && prices[j] > prices[i]; j++);
            if (j < n){
                discount = prices[j];
            }
            answer[i] = prices[i] - discount;
        }
        return answer;
    }
};
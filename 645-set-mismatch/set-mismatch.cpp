class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n + 1, 0);
        int repetition;
        int sum = 0;
        for (int elem : nums){
            if (check[elem] == 1)
                repetition = elem;
            check[elem]++;
            sum += elem;
        }
        return {repetition, n * (n + 1) / 2 - (sum - repetition)};
    }
};
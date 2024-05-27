class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> counter(1001, 0);
        for (int elem : nums){
            counter[elem]++;
        }
        partial_sum(counter.rbegin(), counter.rend(), counter.rbegin());
        for (int i = 0; i <= 1000; i++){
            if (counter[i] == i){
                return i;
            }
        }
        return -1;
    }
};
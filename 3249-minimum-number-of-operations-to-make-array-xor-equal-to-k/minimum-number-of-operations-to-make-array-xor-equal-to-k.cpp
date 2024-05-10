class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int bitXOR = k;
        for (int elem : nums){
            bitXOR ^= elem;
        }
        int answer = 0;
        while (bitXOR > 0){
            answer += bitXOR & 1;
            bitXOR >>= 1;
        }
        return answer;
    }
};
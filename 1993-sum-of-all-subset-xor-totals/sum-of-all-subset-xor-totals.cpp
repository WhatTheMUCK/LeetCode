class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int bitmask = pow(2, n) - 1;
        int answer = 0, temp;
        while (bitmask > 0){
            temp = 0;
            for (int i = 0; i < n; i++){
                if (bitmask & (1 << i)){
                    temp ^= nums[n - (i + 1)];
                }
            }
            answer += temp;
            bitmask--;
        }
        return answer;
    }
};
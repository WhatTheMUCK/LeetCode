class Solution {
public:
    bool canJump(vector<int>& nums) {
        int need = 0;
        for (int j = nums.size() - 2; j >= 0; j--){
            need++;
            if (need <= nums[j]){
                need = 0;
            }
        }
        return need == 0;
    }
};
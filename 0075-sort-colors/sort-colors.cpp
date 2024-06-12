class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lastZero = -1, lastTwo = nums.size();
        for (int i = 0; i < lastTwo; i++){
            if (i <= lastZero)
                continue;
            if (nums[i] == 0){
                swap(nums[i--], nums[++lastZero]);
            } else if (nums[i] == 2){
                swap(nums[i--], nums[--lastTwo]);
            }
        }
        return;
    }
};
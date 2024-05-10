class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int amount = 1;
        for (int i = 1; i < nums.size(); i++){
            if (majority != nums[i]){
                amount--;
            } else {
                amount++;
            }
            if (amount == 0){
                majority = nums[i];
                amount = 1;
            }
        }
        return majority;
    }
};
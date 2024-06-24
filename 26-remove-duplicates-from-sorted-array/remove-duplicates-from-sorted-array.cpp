class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int i = 1;
        // int uniq = 0;
        // while (i < nums.size()){
        //     if (nums[i] == nums[uniq]){
        //         i++;
        //     } else {
        //         uniq++;
        //         nums[uniq] = nums[i]; 
        //     }
        // }
        // return uniq + 1;
        return unique(nums.begin(), nums.end()) - nums.begin();
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lessTwiceUniq = 0;
        int counter = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[lessTwiceUniq] && counter < 2){
                lessTwiceUniq++;
                nums[lessTwiceUniq] = nums[i]; 
                counter++;
            } else if (nums[i] != nums[lessTwiceUniq]) {
                lessTwiceUniq++;
                nums[lessTwiceUniq] = nums[i]; 
                counter = 1;
            }
        }
        return lessTwiceUniq + 1;
    }
};
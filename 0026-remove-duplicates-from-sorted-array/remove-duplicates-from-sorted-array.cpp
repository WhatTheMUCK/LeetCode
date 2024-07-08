class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int uniq = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == nums[uniq])
                continue;
            uniq++;
            swap(nums[uniq], nums[i]);
        }
        return uniq + 1;
    }
};
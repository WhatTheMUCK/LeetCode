class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maximumValue = *max_element(nums.begin(), nums.end());
        int answer = 0;
        int window = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == maximumValue){
                window++;
            } else {
                answer = max(answer, window);
                window = 0;
            }
        }
        return max(answer, window);
    }
};
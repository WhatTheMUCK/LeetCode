class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int answer = 0;
        for (int i = 0; i < nums.size(); i++){
            int more = 1, less = 1;
            while (numSet.contains(nums[i] + more)){
                numSet.erase(nums[i] + more);
                more++;
            }
            while (numSet.contains(nums[i] - less)){
                numSet.erase(nums[i] - less);
                less++;
            }
            answer = max(answer, 1 + (more - 1) + (less - 1));
            numSet.erase(nums[i]);
        }
        return answer;
        
    }
};
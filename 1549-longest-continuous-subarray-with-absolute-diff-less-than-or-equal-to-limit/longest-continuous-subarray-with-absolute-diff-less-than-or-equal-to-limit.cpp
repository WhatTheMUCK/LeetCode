class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int l = 0, answer = 0;
        for (int r = 0; r < nums.size(); r++){
            window.insert(nums[r]);
            while (!window.empty() && abs(*window.begin() - *window.rbegin()) > limit){
                window.erase(window.find(nums[l]));
                l++;
            }
            answer = max(answer, r - l + 1);
        }
        return answer;
    }
};
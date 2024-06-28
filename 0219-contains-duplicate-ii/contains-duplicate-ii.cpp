class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> window;
        int elems = 0, l = 0;
        for (int i = 0; i < nums.size(); i++){
            if (elems == k + 1){
                window[nums[l++]]--;
                elems--;
            }
            if (window[nums[i]] == 1)
                return true;
            window[nums[i]]++;
            elems++;
        }
        return false;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> prefs;
        int pref = nums[0];
        for (int i = 1; i < nums.size(); i++){
            pref += nums[i];
            if (prefs.contains(pref % k) || (pref % k) == 0)
                return true;
            prefs.insert((pref - nums[i]) % k);
        }
        return false;
    }
};

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            nums[i] = nums[i] % 2;
        }

        unordered_map<int, int> pref;
        int prefSum = 0, answer = 0;
        pref[0] = 1;
        for (int i = 0; i < n; i++){
            prefSum += nums[i];
            if (prefSum >= k){
                answer += pref[prefSum - k];
            }
            pref[prefSum]++;
        }
        return answer;
    }
};
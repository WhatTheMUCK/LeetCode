class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pref;
        pref[0] = 1;
        int sum = 0, answer = 0;
        for (int elem : nums){
            sum += elem;
            answer += pref[sum - k];
            pref[sum]++;
        }
        return answer;
    }
};
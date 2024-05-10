class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int answer = -1;
        unordered_set<int> dict;
        for (int elem : nums){
            dict.insert(elem);
            if (dict.contains(-elem) && abs(elem) > answer){
                answer = abs(elem);
            }
        }
        return answer;
    }
};
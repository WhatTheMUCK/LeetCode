class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for (int elem : nums) {
            answer ^= elem;
        }
        return answer;
    }
};
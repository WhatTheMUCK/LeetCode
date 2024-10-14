class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long answer = 0;
        make_heap(nums.begin(), nums.end());
        while (k--){
            double curMax = nums[0];
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            answer += curMax;
            nums.push_back(ceil(curMax / 3));
            push_heap(nums.begin(), nums.end());
        }
        return answer;
    }
};
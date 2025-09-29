class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        deque<int> dq;
        int l = 0, r = static_cast<int>(nums.size()) - 1;
        while (l < r) {
            int lValue = nums[l] * nums[l], rValue = nums[r] * nums[r];
            if (lValue > rValue) {
                dq.push_front(lValue);
                ++l;
            } else {
                dq.push_front(rValue);
                --r;
            }
        }
        dq.push_front(nums[l] * nums[l]);

        return vector<int>(dq.begin(), dq.end());
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int rightest = 0, current = 0, jumps = 0, i = -1;
        while (current < nums.size() - 1){
            i++;
            rightest = max(rightest, i + nums[i]);

            if (i == current){
                jumps++;
                current = rightest;
            }
        }
        return jumps;
    }
};
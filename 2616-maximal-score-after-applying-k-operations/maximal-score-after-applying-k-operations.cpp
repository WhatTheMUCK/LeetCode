class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long answer = 0;
        priority_queue<int> pq_nums(nums.begin(), nums.end());
        while (k--){
            double curMax = pq_nums.top();
            pq_nums.pop();
            answer += curMax;
            pq_nums.push(ceil(curMax / 3));
        }
        return answer;
    }
};
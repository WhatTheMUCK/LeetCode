class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        deque<pair<int, int>> deq;
        int target = 0;
        for (int i = 0; i <= nums.size() - k; i++){
            while (!empty(deq) && deq.front().second < i){
                deq.pop_front();
            }
            while (target < i + k){
                while (!empty(deq) && nums[target] >= deq.back().first){
                    deq.pop_back();
                }
                deq.push_back({nums[target], target});
                target++;
            }
            answer.push_back(deq.front().first);
        }
        return answer;
    }
};
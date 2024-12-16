class Compare{
    public:
        bool operator()(pair<int, int> left, pair<int, int> right){
            if (left.first == right.first){
                return left.second > right.second;
            } 
            return left.first > right.first;
        }
};

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; i++){
            pair<int, int> cur = pq.top();
            pq.pop();
            pq.push({cur.first * multiplier, cur.second});
        }
        while (!pq.empty()){
            auto [value, ind] = pq.top();
            nums[ind] = value;
            pq.pop();
        }

        return nums;
    }
};
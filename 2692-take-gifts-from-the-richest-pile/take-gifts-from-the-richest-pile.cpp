class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>, less<int>> max_priority_queue(gifts.begin(), gifts.end());
        for (int i = 0; i < k; i++){
            int curGift = max_priority_queue.top();
            max_priority_queue.pop();
            max_priority_queue.push((int)sqrt(curGift));
        }
        long long answer = 0;
        while (!max_priority_queue.empty()){
            answer += max_priority_queue.top();
            max_priority_queue.pop();
        }
        return answer;
    }
};
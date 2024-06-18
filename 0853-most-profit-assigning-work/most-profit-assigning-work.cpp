struct ComparePairs {
    bool operator()(const pair<int, int>& left, const pair<int, int>& right) const {
        if (left.second == right.second) {
            return left.first > right.first;
        }
        return left.second < right.second;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq, temp;
        for (int i = 0; i < difficulty.size(); i++){
            pq.push({difficulty[i], profit[i]});
        }
        temp = pq;
        while (!temp.empty()){
            cout << temp.top().first << " " << temp.top().second << "\n";
            temp.pop();
        }
        cout << "\n";
        sort(worker.begin(), worker.end(), greater<int>());
        for (int i = 0; i < worker.size(); i++){
            cout << worker[i] << " ";
        }
        cout << "\n";
        int answer = 0;
       for (int cur = 0; cur < worker.size(); cur++){
            while (!pq.empty() && worker[cur] < pq.top().first)
                pq.pop();
            if (pq.empty())
                break;
            answer += pq.top().second;
        }
        return answer;
    }
};
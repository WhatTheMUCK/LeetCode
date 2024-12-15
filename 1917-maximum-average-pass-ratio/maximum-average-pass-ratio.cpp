class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Лямбда-функция для компаратора
        auto comp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return (lhs[0] + 1) / (double)(lhs[1] + 1) - lhs[0] / (double)lhs[1] < (rhs[0] + 1) / (double)(rhs[1] + 1) - rhs[0] / (double)rhs[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, function<bool(const vector<int>&, const vector<int>&)>> pq(comp, classes);

        while (extraStudents--){
            vector<int> curClass = pq.top();
            pq.pop();
            curClass[0]++, curClass[1]++;
            pq.push(curClass);
        }

        double answer = 0;
        while (!pq.empty()){
            vector<int> curClass = pq.top();
            answer += curClass[0] / (double)curClass[1];
            pq.pop();
        }

        return answer / classes.size();
    }
};
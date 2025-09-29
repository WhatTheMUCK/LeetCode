class RecentCounter {
public:
    RecentCounter() : gap(3000) {}

    void clear(int curTime) {
        while (!q.empty() && q.front() < curTime - gap) {
            q.pop();
        }
        return;
    }

    int ping(int t) {
        q.push(t);
        clear(t);

        return q.size();
    }

    queue<int> q;
    int gap;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
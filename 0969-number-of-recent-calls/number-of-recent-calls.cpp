
class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        clean(t);
        q.push(t);
        return q.size();
    }
    
    void clean(int t){
        while (!q.empty() && q.front() < t - 3000)
            q.pop();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
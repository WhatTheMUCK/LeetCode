class MinStack {
private:
    stack<pair<int, int>> minstack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minstack.empty()){
            minstack.push({val, val});
        } else {
            minstack.push({val, min(val, minstack.top().second)});
        }
    }
    
    void pop() {
        minstack.pop();
    }
    
    int top() {
        return minstack.top().first;
    }
    
    int getMin() {
        return minstack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
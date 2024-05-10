class MinStack {
public:
    stack<pair<int, int>> structure;
    MinStack() { 
    }
    
    void push(int val) {
        if (empty(structure)){
            structure.push({val, val});
        } else {
            structure.push({val, min(val, structure.top().second)});
        }
    }
    
    void pop() {
        structure.pop();
    }
    
    int top() {
        return structure.top().first;
    }
    
    int getMin() {
        return structure.top().second;
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
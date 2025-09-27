class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        in.push(x);
        return;
    }
    
    int pop() {
        int answer;
        if (!out.empty()) {
            answer = out.top();
            out.pop();
            return answer;
        }

        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }

        if (!out.empty()) {
            answer = out.top();
            out.pop();
            return answer;
        }

        return -1;
    }
    
    int peek() {
        if (!out.empty()) {
            return out.top();
        }

        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }

        if (!out.empty()) {
            return out.top();
        }

        return -1;

    }
    
    bool empty() {
       return in.empty() && out.empty();
    }

    std::stack<int> in, out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
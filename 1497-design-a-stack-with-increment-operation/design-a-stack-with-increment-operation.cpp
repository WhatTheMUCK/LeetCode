class CustomStack {
public:
    deque<int> st;
    stack<int> temp;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (st.size() < maxSize)
            st.push_front(x);
    }
    
    int pop() {
        if (st.empty())
            return -1;
        int top = st.front();
        st.pop_front();
        return top;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k && !st.empty(); i++){
            temp.push(st.back() + val);
            st.pop_back();
        }
        while (!temp.empty()){
            st.push_back(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
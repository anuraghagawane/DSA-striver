class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini = INT_MIN;
    }
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        }
        else if(val > mini) {
            st.push(val);
        }
        else {
            long long mod_val = 2*(long long)val - mini;
            st.push(mod_val);
            mini = val;
        }
    }
    
    void pop() {
        if(st.top() < mini) {
            mini = 2*mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini) {
            return mini;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        return mini;
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
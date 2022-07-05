class MinStack {
public:
    
    stack<int> st;
    int mn = INT_MAX;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(mn >= val) {
            st.push(mn);
            mn = val;
        }
        st.push(val);
        
    }
    
    void pop() {
        
        if(st.top() == mn) {
            st.pop();
            mn = st.top();
        }
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn;
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
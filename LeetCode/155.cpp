class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if (m.empty() || x <= m.top())
            m.push(x);
    }
    
    void pop() {
        if (st.top() == m.top()) {
            m.pop();
            st.pop();
        }
        else
            st.pop();
    }
    
    int top() {
        return st.top();    
    }
    
    int getMin() {
        return m.top();
    }
private:
    stack<long long int> st;
    stack<long long int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        if (temp.empty())
            st.push(x);
        else {
            while (!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }
            st.push(x);
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (temp.empty()) {
            while (!st.empty()) {
                temp.push(st.top());
                st.pop();
            }
        }
        temp.pop();
    }

    // Get the front element.
    int peek(void) {
        if (!temp.empty())
            return temp.top();
        else {
            while (!st.empty()) {
                temp.push(st.top());
                st.pop();
            }
            return temp.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if (st.empty() && temp.empty())
            return true;
        return false;
    }
private:
    stack<int> st;
    stack<int> temp;
};

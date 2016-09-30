class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q.size() != 1) {
            temp.push(q.front());
            q.pop();
        }
        q.pop();
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }

    // Get the top element.
    int top() {
        while (q.size() != 1) {
            temp.push(q.front());
            q.pop();
        }
        int ret = q.front();
        temp.push(ret);
        q.pop();
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        if (q.empty())
            return true;
        return false;
    }
private:
    queue<int> q;
    queue<int> temp;
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        
        int max = INT_MIN;
        int area;
        int i;
        for (i = 0; i < heights.size();) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i);
                i++;
                continue;
            }
            
            int top = st.top();
            st.pop();
            if (st.empty()) {
                area = heights[top]*i;
            }
            else {
                area = heights[top]*(i - st.top() - 1);
            }
            
            max = std::max(area, max);
        }
        
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            if (st.empty())
                area = heights[top]*i;
            else
                area = heights[top]*(i - st.top() - 1);
            
            max = std::max(area, max);
        }
        
        return (max != INT_MIN) ? max : 0;
        
    }
};

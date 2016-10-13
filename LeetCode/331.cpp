class Solution {
public:
    bool isValidSerialization(string preorder) {
    
        stack<char> st;
        for (int i = 0; i < preorder.length(); i++) {
            if (preorder[i] == ',')
                continue;
            
            st.push(preorder[i]);
            while (preorder[i] != ',' && i < preorder.length())
                i++;
            i--;
            while (st.size() >= 3) {
                int top = st.top();
                st.pop();
                int secondTop = st.top();
                st.pop();
                int thirdTop = st.top();
                st.pop();
                
                if (top == secondTop && top == '#' && thirdTop != '#')
                    st.push('#');
                else {
                    st.push(thirdTop);
                    st.push(secondTop);
                    st.push(top);
                    break;
                }
            }
        }
        
        if (st.size() == 1 && st.top() == '#')
            return true;
        
        return false;
         
    }
};

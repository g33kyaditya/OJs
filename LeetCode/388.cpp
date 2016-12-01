class Solution {
public:
    int lengthLongestPath(string input) {
        
        istringstream ss(input);
        string str;
        stack<int> st;
        int ans = 0;
        while (getline(ss, str, '\n')) {
            
            int cur = str.length();
            int level = 0;
            while (str[level] == '\t')
                level++;
            
            cur = cur - level;
            
            while (st.size() > level)
                st.pop();
            
            cur += (st.empty()) ? 0 : st.top() + 1;
            if (str.find('.') == -1)
                st.push(cur);
            else
                ans = max(ans, cur);
        }
        return ans;
    }
};

class Solution {
public:
    
    void gen(int left, int right, string str, vector<string>& ans) {
        if (right == 0) {
            ans.push_back(str);
            return;
        }
        
        if (left > 0) {
            gen(left-1, right, str + "(", ans);
            if (left < right)
                gen(left, right-1, str + ")", ans);
        }
        else
            gen(left, right-1, str + ")", ans);
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string ret = "";
        gen(n, n, ret, ans);
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.empty())
            return ans;
            
        string curr = strs[0];
        for (int i = 0; i < curr.length(); i++) {
            char ch = curr[i];
            bool stat = true;
            for (int j = 1; j < strs.size(); j++) {
                string t = strs[j];
                if (i >= t.length() || t[i] != ch) {
                    stat = false;
                    return ans;
                }
            }
            
            if (stat)
                ans = ans + ch;
        }
        return ans;
    }
};

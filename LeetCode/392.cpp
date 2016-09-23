class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if (s.empty())
            return true;
        
        int i = 0;
        int j = 0;
        bool ans = false;
        while (i < s.length() && j < t.length()) {
            
            if (s[i] == t[j]) {
                i++;
                j++;
                continue;
            }
            else
                j++;
        }
        
        if (i == s.length())
            ans = true;
        
        return ans;
    }
};

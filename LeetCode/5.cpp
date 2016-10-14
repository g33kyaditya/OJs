class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        if (s.empty())
            return ans;
        
        int maxLen, start;
        bool dp[s.length()][s.length()];
        
         memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
            start = 0;
            maxLen = 1;
        }
        
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        int n = s.length();
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n-len + 1; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

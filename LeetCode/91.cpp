class Solution {
public:
    int numDecodings(string s) {
        
        if (s.empty() || s[0] == '0')
            return 0;
        
        if (s.length() == 1)
            return 1;
        
        int n = s.length();
        unsigned long long int dp[n+5]={0};
        int x,ans;
        dp[0]=1;
        for (int i=1;i<s.length();i++) {
            x = (s[i-1]-'0')*10 + (s[i]-'0');
            if (s[i]-'0')
                dp[i] = dp[i-1];
            if (x>=10 && x<=26) {
                int k = i-2;
                if (k >= 0) 
                    dp[i] = dp[i] + dp[i-2];
                else
                    dp[i] = dp[i] + dp[0];
            }
        }
        return dp[n-1];
    }
};

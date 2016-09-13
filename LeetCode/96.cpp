class Solution {
public:
    
    int foo(int n, int * dp) {

        if (n == 0 || n == 1)
            return 1;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i-1] == -1)
                dp[i-1] = foo(i-1, dp);
            
            if (dp[n-i] == -1)
                dp[n-i] = foo(n-i, dp);
            
            ans = ans + dp[i-1]*dp[n-i];
        }
        return ans;
    }

    int numTrees(int n) {
        int dp[n+1];
        for (int i = 0; i <= n; i++)
            dp[i] = -1;
    
        return foo(n, dp);
    }
};

class Solution {
public:
    int integerBreak(int n) {
        switch (n) {
            case 0: return 0;
                    break;
            
            case 1: return 0;
            
            case 2: return 1;
            
            case 3: return 2;
            
            case 4: return 4;
            
            case 5: return 6;
            
            case 6: return 9;
        }
        
        int dp[n+1]; 
        dp[0] = 0;
        dp[1] = 0; 
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        for (int i = 7; i <= n; i++)
            dp[i] = dp[i-3]*3;
        
        return dp[n];
    }
};

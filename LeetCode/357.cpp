class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if (n == 0)
            return 1;
        
        if (n == 1)
            return 10;
        
        int dp[n+1];
        dp[0] = 1;
        
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 9;
            for (int j = 9; j >= 11 - i; j--)
                dp[i] = dp[i]*j;
        }
        
        for (int i = 0; i < n+1; i++)
            sum += dp[i];

        return sum;
    }
};

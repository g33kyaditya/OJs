class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if (amount == 0)
            return 0;
        
        int *dp = new int[amount+1];
        for (int i = 1; i <= amount; i++)
            dp[i] = INT_MAX;

        dp[0] = 0;
        
        for (int amt = 1; amt <= amount; amt++) {
            for (int j = 0; j < coins.size(); j++) {
                if (amt >= coins[j] && dp[amt - coins[j]] != INT_MAX)
                    dp[amt] = std::min(dp[amt], 1 + dp[amt - coins[j]]);
            }
        }
        
        if (dp[amount] == INT_MAX)
            return -1;

        return dp[amount];
    }
};

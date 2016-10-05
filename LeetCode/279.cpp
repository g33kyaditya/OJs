class Solution {
public:
    int numSquares(int n) {
        vector<int> vec;
        for (int i = 1; i*i <= n; i++)
            vec.push_back(i*i);
        
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < vec.size(); j++) {
                if (vec[j] <= i) {
                    dp[i] = std::min(dp[i], 1 + dp[i - vec[j]]);
                }
            }
        }
        return dp[n];
        
    }
};

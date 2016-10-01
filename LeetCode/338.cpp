class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= num; i++) {
            if (i&(i-1) == 0) {
                dp[i] = 1;
            }
            else {
                int closest = floor(log2(i));
                closest = pow(2, closest);
                dp[i] = 1 + dp[i-closest];
            }
        }
        return dp;
    }
};

class Solution {
public:
    int foo(vector<vector<int>>& triangle, int r, int c, vector<vector<int>>&dp) {
        
        if (r < 0 || c < 0 || r >= triangle.size() || c >= triangle[r].size())
            return 0;
        
        if (r == triangle.size()-1)
            return triangle[r][c];
        
        if (dp[r][c] != INT_MAX)
            return dp[r][c];

        int below = triangle[r][c] + foo(triangle, r+1, c, dp);
        int right = triangle[r][c] + foo(triangle, r+1, c+1, dp);
        dp[r][c] = std::min(below, right);
        return dp[r][c];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        if (triangle[0].empty())
            return 0;
        
        vector<vector<int>>dp;
        dp.resize(triangle.size());
        for (int i = 0; i < triangle.size(); i++)
            dp[i].resize(triangle[i].size());
        
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++)
                dp[i][j] = INT_MAX;
        }
        
        return foo(triangle, 0, 0, dp);
    }
};

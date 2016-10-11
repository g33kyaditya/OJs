class Solution {
public:
    
    int sum(vector<int>& vec) {
        int ret = 0;
        for (int i = 0; i < vec.size(); i++)
            ret += vec[i];
        
        return ret;
    }
    
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
            return false;

        int needed = sum(nums);
        if (needed%2 != 0)
            return false;
        
        needed = needed/2;
        
        bool dp[needed + 1][nums.size()+1];
        
        for (int i = 0; i <= nums.size(); i++)
            dp[0][i] = true;
        
        for (int i = 1; i <= needed; i++)
            dp[i][0] = false;            

        for (int i = 1; i <= needed; i++) {
            for (int j = 1; j <= nums.size(); j++) {
                dp[i][j] = dp[i][j-1];
                if (nums[j-1] <= i) {
                    dp[i][j] = dp[i][j] || dp[i - nums[j-1]][j-1];
                }
            }
        }
        return dp[needed][nums.size()];
    }
};

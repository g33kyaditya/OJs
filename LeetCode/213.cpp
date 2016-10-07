class Solution {
public:
    int foo(vector<int>&nums, int lo, int hi) {
        if (lo == hi)
            return nums[lo];

        int dp[nums.size()];
        dp[lo] = nums[lo];
        dp[lo+1] = max(nums[lo], nums[lo+1]);
        for (int i = lo+2; i <= hi; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);

        return dp[hi];
    }

    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
        
        if (nums.size() == 2)
            return std::max(nums[0], nums[1]);
        
        int f1 = foo(nums, 0, nums.size()-2);
        int f2 = foo(nums, 1, nums.size()-1);
        
        return std::max(f1, f2);
    }
    
};

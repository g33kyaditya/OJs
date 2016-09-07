class NumArray {
public:
    int *dp;
    NumArray(vector<int> &nums) {
        if (nums.empty())
            return;
            
        dp = new int [nums.size()];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            dp[i] = dp[i-1] + nums[i];
    }

    int sumRange(int i, int j) {
       return dp[j] - dp[i-1];
    }

};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

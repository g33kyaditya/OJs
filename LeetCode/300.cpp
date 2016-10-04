class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int>lis(n, 0);
        int ans = INT_MIN;
        for (int j = 0; j < n; j++) {
            lis[j] = 1;
            for (int i = 0; i < j; i++) {
                if (nums[j] > nums[i]) {
                    lis[j] = std::max(lis[j], lis[i]+1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (lis[i] > ans)
                ans = lis[i];
        }
        return ans;
    }
};

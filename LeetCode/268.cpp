class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = (n*(n+1))/2;
        int cur = 0;
        for (int i = 0; i < n; i++)
            cur = cur + nums[i];
        
        return expectedSum - cur;
    }
};

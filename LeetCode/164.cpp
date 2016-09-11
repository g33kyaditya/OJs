class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        
        sort(nums.begin(), nums.end());
        int max = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] > max)
                max = nums[i] - nums[i-1];
        }
        return max;
    }
};

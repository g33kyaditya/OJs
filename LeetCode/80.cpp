class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.empty())
            return 0;
        
        int n = nums.size();
        vector<int> ans;
        if (n == 2 || n == 1)
            return nums.size();
        
        int ct = 0;
        if (n > 0) {
            ans.push_back(nums[0]);
            ct++;
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) {
                ct++;
                if (ct <= 2)
                    ans.push_back(nums[i]);
            }
            else {
                ans.push_back(nums[i]);
                ct = 1;
            }
        }
        
        nums.clear();
        nums = ans;
        return nums.size();
    }
};

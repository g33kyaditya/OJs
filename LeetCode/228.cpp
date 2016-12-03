class Solution {
public:
    string createRange(int lo, int hi) {
        if (lo == hi)
            return std::to_string(lo);
        return std::to_string(lo) + "->" + std::to_string(hi);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty())
            return ans;
        
        int lo = nums[0];
        int i;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1)
                continue;
            else {
                string range = createRange(lo, nums[i-1]);
                lo = nums[i];
                ans.push_back(range);
            }
        }
        
        string range = createRange(lo, nums[i-1]);
        lo = nums[i];
        ans.push_back(range);
        return ans;
    }
};

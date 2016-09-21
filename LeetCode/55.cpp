class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int jumps = nums[0];
        int i = 0;
        while (i < nums.size()-1) {
            if (jumps == 0)
                return false;
            
            jumps--;
            i++;
            jumps = max(jumps, nums[i]);
        }
        return true;
        
    }
};

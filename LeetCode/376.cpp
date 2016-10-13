class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if (nums.size() < 2)
            return nums.size();
        
        int pos[nums.size()];
        int neg[nums.size()];
        
        pos[0] = 1;
        neg[0] = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                pos[i] = neg[i-1] + 1;
                neg[i] = neg[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                neg[i] = pos[i-1] + 1;
                pos[i] = pos[i-1];
            }
            else {
                pos[i] = pos[i-1];
                neg[i] = neg[i-1];
            }
        }
        return std::max(pos[nums.size()-1], neg[nums.size()-1]);
    }
};

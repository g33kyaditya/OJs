class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int start = 0;
        int last = nums.size()-1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val)
                nums[start++] = nums[i];
        }
        return start;
           
    }
};

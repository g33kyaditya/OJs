class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
 
        if (smallest >= nums[i]) {
            smallest = nums[i];
            } 
            else if (secondSmallest >= nums[i])
                secondSmallest = nums[i]; 
            else
                return true;
        }
        return false;
        
    }
};

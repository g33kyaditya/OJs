class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
        bool allNeg = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                allNeg = false;
                break;
            }
        }
        
        if (allNeg) {
            int max = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > max)
                    max = nums[i];
            }
            return max;
        }
        
        int max = INT_MIN;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            if (sum < 0)
                sum = 0;
            
            if (max < sum)
                max = sum;
        }
        
        return max;
      
    }
};

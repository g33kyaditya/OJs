class Solution {
public:
    int findMin(vector<int>& nums) {
    
        int l = 0;
        int h = nums.size()-1;
        int mid;
        
        if (nums[l] <= nums[h])
            return nums[l];
        
        while (l <= h) {
            mid = (l+h)/2;
            
            if (nums[mid] > nums[mid+1])
                return nums[mid+1];
            
            else if (nums[l] <= nums[mid])
                l = mid + 1;
            
            else
                h = mid - 1;
            
        }
        return nums[l];
    }
};

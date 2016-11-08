class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int i = 0; i  < nums.size(); i++)
            if (nums[i] == target)
                return true;
        
        return false;
    }
};



============================================================


class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int lo = 0;
        int hi = nums.size()-1;
        int mid;
        while (lo <= hi) {
            mid = (lo + hi)/2;
            if (nums[mid] == target)
                return true;

            else if (nums[lo] < nums[mid]) {
                if (target >= nums[lo] && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            } else if (nums[lo] > nums[mid]) {
                if(target > nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            } else {
                lo++;
            }
        }
        
        return false;
    }
};

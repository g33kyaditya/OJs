class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int l = 0;
        int h = nums.size()-1;
        int mid;
        while (l <= h) {
            mid = (l+h)/2;
            if (nums[mid] == target) {
                int k = mid;
                while (nums[k] == target && k >= 0)
                    k--;
                ans.push_back(k+1);
                
                k = mid;
                while (nums[k] == target && k <= h)
                    k++;
                ans.push_back(k-1);
                break;
            }
            else if (nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        
        if (ans.empty()) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        return ans;
    }
};



===========================================================================

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if (nums.empty())
            return ans;
        int lo = 0;
        int hi = nums.size()-1;
        int mid;
        int leftMost = -1;
        while (lo <= hi) {
            mid = (lo + hi)/2;
            if (nums[mid] == target) {
                leftMost = mid;
                hi = mid - 1;
            }
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        int rightMost = -1;
        
        lo = 0;
        hi = nums.size()-1;
        while (lo <= hi) {
            mid = (lo + hi)/2;
            if (nums[mid] == target) {
                rightMost = mid;
                lo = mid + 1;
            }
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        ans.push_back(leftMost);
        ans.push_back(rightMost);
        
        return ans;
    }
};

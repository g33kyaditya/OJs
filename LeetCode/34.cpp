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

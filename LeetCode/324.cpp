class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2;
        if (nums.size()%2 == 0 && mid >= 1)
            mid--;
        
        int last = nums.size() - 1;
        vector<int> v;
        int m = mid;
        while (mid >= 0) {
            v.push_back(nums[mid]);
            mid--;
            if (last != m) {
                v.push_back(nums[last]);
                last--;
            }
        }
        nums.clear();
        nums = v;
    }
};

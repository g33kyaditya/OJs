class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        int t = pow(2,n);
        int i = 0;
        while (i < t) {
            vector<int> temp;
            int cur = i;
            for (int j = 0; j < n; j++) {
                if (cur & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};

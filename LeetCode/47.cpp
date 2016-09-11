class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        bool yes = true;
        while(yes) {
            ans.push_back(nums);
            yes = next_permutation(nums.begin(), nums.end());
        }
        
        return ans;
    }
};

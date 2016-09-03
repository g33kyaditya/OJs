class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prev[nums.size()];
        int next[nums.size()];
        
        int n = nums.size();
        
        prev[0] = 1;
        next[nums.size()-1] = 1;
        
        for (int i = nums.size()-2; i >= 0; i--)
            next[i] = next[i+1]*nums[i+1];
        
        for (int i = 1; i < nums.size(); i++)
            prev[i] = prev[i-1]*nums[i-1];
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int mul = prev[i]*next[i];
            ans.push_back(mul);
        }
        return ans;
    }
};

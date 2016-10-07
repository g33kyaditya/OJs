class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        vector<vector<int>>ret;
        
        if (nums.empty())
            return ret;
        int total = pow(2, nums.size());
        int t = nums.size();
        for (int i = 0; i < total; i++) {
            vector<int>cur;
            int temp = i, ctr = 0;
            while(ctr < t) {
                if (temp&1)
                    cur.push_back(nums[ctr]);
                
                temp = temp >> 1;
                ctr++;
            }
            sort(cur.begin(), cur.end());
            ans.insert(cur);
        }
        
        auto it = ans.begin();
        for(; it != ans.end(); it++) {
            ret.push_back(*it);
        }
        return ret;
    }
};

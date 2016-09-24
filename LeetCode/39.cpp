class Solution {
public:

    void foo(vector<int>& candidates, int target, set<vector<int>>& p, vector<int>&ret, int index) {
        
        if (target == 0) {
            p.insert(ret);
            return;
        }
        
        if (target < 0)
            return;
        
        while (index < candidates.size() && target - candidates[index] >= 0) {
            ret.push_back(candidates[index]);
            foo(candidates, target - candidates[index], p, ret, index);
            index++;
            ret.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>>p;
        if (candidates.empty())
            return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> r;
        foo(candidates, target, p, r, 0);
        set<vector<int>>::iterator it = p.begin();
        for (it; it != p.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};

class Solution {
public:
    void findSum(vector<int>& candidates, int target, vector<int> cur, set<vector<int>>&s, int index) {
        if (target == 0) {
            s.insert(cur);
            return;
        }
        
        if (index >= candidates.size())
            return;
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                findSum(candidates, target - candidates[i], cur, s, i + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        set<vector<int>> s;
        
        if (candidates.empty())
            return ans;
        
        sort(candidates.begin(), candidates.end());
        findSum(candidates, target, cur, s, 0);
        
        for (auto it = s.begin(); it != s.end(); it++) {
            ans.push_back(*it);
        }
        
        return ans;
    }
};

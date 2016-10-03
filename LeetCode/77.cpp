class Solution {
public:
    void foo(int start, int k, vector<int> ret, vector<vector<int>>&ans, vector<int>& pool) {
        if (ret.size() == k) {
            ans.push_back(ret);
            return;
        }
        
        for (int i = start; i < pool.size(); i++) {
            ret.push_back(i);
            foo(i+1, k, ret, ans, pool);
            ret.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ret;
        vector<int> pool(n+1);
        for (int i = 1; i <= n; i++)
            pool[i] = i;

        foo(1, k, ret, ans, pool);
        return ans;
    }
};

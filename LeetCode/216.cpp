class Solution {
public:
    void foo(int n, int k, vector<vector<int>>& ans, vector<int>vec, vector<int>pool, int index, vector<bool>visited) {
        
        if (n < 0)
            return;
        
        if (n == 0 && vec.size() == k) {
            ans.push_back(vec);
            return;
        }
        
        for (int j = index; j < pool.size(); j++) {
            if (pool[j] <= n && !visited[pool[j]]) {
                vec.push_back(pool[j]);
                visited[pool[j]] = true;
                foo(n - pool[j], k, ans, vec, pool, j, visited);
                vec.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ret;
        vector<int>pool = {1,2,3,4,5,6,7,8,9};
        vector<bool> visited(10, false);
        foo(n, k, ans, ret, pool, 0, visited);

        return ans;
    }
};

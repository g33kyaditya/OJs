class Solution {
public:
    void foo(int n, int k, vector<vector<int>>& ans, vector<int>vec, vector<bool>visited) {
        
        if (n < 0)
            return;
        
        if (n == 0 && vec.size() == k) {
            ans.push_back(vec);
            return;
        }
        
        for (int j = 1; j <= 9; j++) {
            if (j <= n && !visited[j]) {
                vec.push_back(j);
                visited[j] = true;
                foo(n - j, k, ans, vec, visited);
                vec.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ret;
        vector<bool> visited(10, false);
        foo(n, k, ans, ret, visited);

        return ans;
    }
};

class Solution {
public:
    void dfs(int cur, int n, vector<int>& res) {
        for (int i = 0; i <= 9; i++) {
            int temp = cur*10 + i;
            if (temp > n)
                break;
            
            res.push_back(temp);
            dfs(temp, n, res);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i<=n && i<=9; i++) {
            ans.push_back(i);
            dfs(i, n, ans);
        }
        return ans;
    }
};

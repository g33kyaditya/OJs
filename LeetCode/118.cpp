class Solution {
public:
    
    long long int fact(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; i++)
            ans = ans*i;
        
        return ans;
    }
    
    long long int com(int n, int r) {
        long long int ans = 1;
        
        if (r < n-r) {
            for (int i = n; i > n-r; i--)
                ans = ans*i;
            
            return ans/fact(r);
        }
        else {
            for (int i = n; i > r; i--)
                ans = ans*i;
            
            return ans/fact(n-r);
        }
        
    }
    vector<vector<int>> generate(int numRows) {
    
       vector<vector<int>> ans;
       for (int i = 0; i < numRows; i++) {
           // find iCj
            vector<int> level;
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    level.push_back(1);
                    continue;
                }
                else {
                    long long int ans = com(i, j);
                    level.push_back(ans);
                }
            }
            ans.push_back(level);
       }
       
       return ans;
    }
};

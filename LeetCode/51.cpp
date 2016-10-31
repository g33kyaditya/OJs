class Solution {
public:
    bool hit(vector<string> vec, int R, int C) {
        for (int c = 0; c < C; c++) {
            if (vec[R][c] == 'Q')
                return true;
        }
        
        int r = R, c = C;
        while (r >= 1 && c >= 1) {
            if (vec[r-1][c-1] == 'Q')
                return true;
            
            r--;
            c--;
        }
        
        r = R;
        c = C;
        while (r < vec.size() - 1 && c >= 1) {
            if (vec[r+1][c-1] == 'Q')
                return true;
            r++;
            c--;
        }
        
        return false;
    }
    
    bool solve(int n, int col, vector<vector<string>>&ans, vector<string> cur) {
        if (n == col)
            return true;
        
        for (int r = 0; r < n; r++) {
            if (!hit(cur, r, col)) {
                cur[r][col] = 'Q';
                if (solve(n, col + 1, ans, cur)) {
                    ans.push_back(cur);
                    cur[r][col] = '.';
                }
                else {
                    cur[r][col] = '.';
                }
            }
        }
        return false;
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur;
        cur.resize(n);
        for (int i = 0; i < cur.size(); i++) {
            for (int j = 0; j < n; j++)
                cur[i] += ".";
        }
        
        solve(n, 0, ans, cur);
        return ans;
    }
};

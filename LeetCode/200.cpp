class Solution {
public:
    void DFS(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return;

        if (grid[r][c] == '1') {
            grid[r][c] = '2'; //visited
            DFS(grid, r, c - 1);
            DFS(grid, r, c + 1);
            DFS(grid, r - 1, c);
            DFS(grid, r + 1, c);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int R = grid.size();
        
        if (R == 0)
            return 0;

        int C = grid[0].size();
    
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == '1') {
                    DFS(grid, r, c);
                    count++;
                }
            }
        }
        return count;
    }
};

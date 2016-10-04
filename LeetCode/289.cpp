class Solution {
public:
    int findNeighbors(vector<vector<int>>&board, int r, int c) {
        int R = board.size();
        int C = board[0].size();
        
        int count = 0;
        
        //Horizontal
        if (c+1 < C && board[r][c+1] == 1)
            count++;
        
        if (c-1 >= 0 && board[r][c-1] == 1)
            count++;
        
        //Vertical
        if (r-1 >= 0 && board[r-1][c] == 1)
            count++;
        
        if (r+1 < R && board[r+1][c] == 1)
            count++;
        
        //Diagonals
        if (r-1 >= 0 && c-1 >= 0 && board[r-1][c-1] == 1)
            count++;
        
        if (r+1 < R && c+1 < C && board[r+1][c+1] == 1)
            count++;
        
        if (r-1 >= 0 && c+1 < C && board[r-1][c+1] == 1)
            count++;
        
        if (r+1 < R && c-1 >= 0 && board[r+1][c-1] == 1)
            count++;
        
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int R = board.size();
        int C = board[0].size();
        vector<vector<int>>res;
        res.resize(R);
        for (int i = 0; i < R; i++)
            res[i].resize(C);
        
        res = board;
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                
                int neighbors = findNeighbors(board, i, j);
                if (board[i][j] == 1) {
                    if (neighbors < 2)
                        res[i][j] = 0;
                    else if (neighbors == 2 || neighbors == 3)
                        res[i][j] = 1;
                    else if (neighbors > 3)
                        res[i][j] = 0;
                    
                }
                else {
                    if (neighbors == 3)
                        res[i][j] = true;
                }
            }
        }
        
        board = res;
    }
};

class Solution {
public:
    void floodFill(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& visited) {

        queue<pair<int,int>>q;
        q.push(make_pair(r,c));
        visited[r][c] = true;
        while (!q.empty()) {
            
            pair<int,int> front = q.front();
            q.pop();
            
            int R = front.first;
            int C = front.second;

            board[R][C] = 'O';
            
            
            //top
            if (R-1 >= 0 && board[R-1][C] == '!' && !visited[R-1][C]) {
                q.push(make_pair(R-1, C));
                visited[R-1][C] = true;
            }
            
            //bottom
            if (R+1 < board.size() && board[R+1][C] == '!' && !visited[R+1][C]) {
                q.push(make_pair(R+1, C));
                visited[R+1][C] = true;
            }
            
            //left
            if (C-1 >= 0 && board[R][C-1] == '!' && !visited[R][C-1]) {
                q.push(make_pair(R, C-1));
                visited[R][C-1] = true;
            }
            
            //right
            if (C+1 < board[0].size() && board[R][C+1] == '!' && !visited[R][C+1]) {
                q.push(make_pair(R, C+1));
                visited[R][C+1] = true;
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        
        if (board[0].empty())
            return;
        
        int R = board.size();
        int C = board[0].size();
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = '!';
            }
        }
        
        vector<vector<bool>>visited(R, vector<bool>(C, false));

        for (int r = 0; r < R; r++)
            if (board[r][0] == '!')
                floodFill(board, r, 0, visited);
        
        for (int r = 0; r < R; r++)
            if (board[r][C-1] == '!')
                floodFill(board, r, C-1, visited);
        
        for (int c = 0; c < C; c++)
            if (board[0][c] == '!')
                floodFill(board, 0, c, visited);
    
        for (int c = 0; c < C; c++)
            if (board[R-1][c] == '!')
                floodFill(board, R-1, c, visited);
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == '!')
                    board[i][j] = 'X';
            }
        }
    }
};

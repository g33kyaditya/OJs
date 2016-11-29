class Solution {
public:
    bool findNeighbors(vector<vector<char>>board, string word, int r, int c, int curIn) {
        
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
            return false;
        
        if (curIn >= word.size())
            return true;
        
        char next = word[curIn];
        
        if (r > 0 && board[r-1][c] == next) {
            board[r-1][c] = '!';
            bool ret = findNeighbors(board,word, r-1, c, curIn + 1);
            board[r-1][c] = next;
            if(ret) return true;
        }
        
        if (c > 0 && board[r][c-1] == next) {
            board[r][c-1] = '!';
            bool ret = findNeighbors(board,word, r, c-1, curIn + 1);
            board[r][c-1] = next;
            if(ret) return true;
        }
        
        if (r < board.size()-1 && board[r+1][c] == next) {
            board[r+1][c] = '!';
            bool ret = findNeighbors(board,word, r+1, c, curIn + 1);
            board[r+1][c] = next;
            if(ret) return true;
        }
        
        if (c < board[0].size()-1 && board[r][c+1] == next) {
            board[r][c+1] = '!';
            bool ret = findNeighbors(board,word, r, c+1, curIn + 1);
            board[r][c+1] = next;
            if(ret) return true;
        }
        
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int i = 0;
        int z = 0;
        bool ret = false;
        int R = board.size();
        int C = board[0].size();
        int T = word.size()-1;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                
                if (board[i][j] == word[0]) {
                    board[i][j] = '!';
                    bool ret = findNeighbors(board, word, i, j, 1);
                    board[i][j] = word[0];
                    if(ret) return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    
    bool isNumber(char ch) {
        if ('1' <= ch && ch <= '9')
            return true;
        return false;
    }
    
    bool validRow(vector<vector<char>>& board) {
        
        for (int r = 0; r < board.size(); r++) {
            bool arr[10];
            memset(arr, false, sizeof(arr));
            for (int c = 0; c < board[0].size(); c++) {
                if (isNumber(board[r][c])) {
                    int num = board[r][c] - '0';
                    if (arr[num])
                        return false;
                    else
                        arr[num] = true;
                }
            }
        }
        return true;
    }

    bool validColumn(vector<vector<char>>& board) {

        for (int c = 0; c < board[0].size(); c++) {
            bool arr[10];
            memset(arr, false, sizeof(arr));
            for (int r = 0; r < board.size(); r++) {
                if (isNumber(board[r][c])) {
                    int num = board[r][c] - '0';
                    if (arr[num])
                        return false;
                    else
                        arr[num] = true;
                }
            }
        }
        return true;
    }
    
    bool validMat(vector<vector<char>>& board, int r, int c, int R, int C) {
        bool arr[10] = {false};
        
        for (int i = r; i <= R; i++) {
            for (int j = c; j <= C; j++) {
                if (isNumber(board[i][j])) {
                    int num = board[i][j] - '0';
                    if (arr[num])
                        return false;
                    else
                        arr[num] = true;
                }
            }
        }
        return true;
    }
    
    bool validMatrix(vector<vector<char>>& board) {
        int lowR, lowC, highR, highC;
        bool ret = true;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (r < 3) {
                        lowR = 0;
                        highR = 2;
                    }
                else if (r < 6) {
                    lowR = 3;
                    highR = 5;
                }
                else {
                    lowR = 6;
                    highR = 8;
                }
                    
                    
                if (c < 3) {
                    lowC = 0;
                    highC = 2;
                }
                else if (c < 6) {
                    lowC = 3;
                    highC = 5;
                }
                else {
                    lowC = 6;
                    highC = 8;
                }
                
                if (!validMat(board, lowR, lowC, highR, highC))
                    return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
       int R = board.size();
       int C = board[0].size();
       
       if (R != 9 || C != 9)
        return false;
        
        if (validRow(board) && validColumn(board) && validMatrix(board))
            return true;
       
       return false;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        if (matrix[0].empty())
            return;
        
        bool rZ = false;
        bool cZ = false;
        
        for (int i = 0; i < matrix[0].size();i++) {
            if (matrix[0][i] == 0) {
                rZ = true;
                break;
            }
        }
        
        for (int i = 0; i < matrix.size();i++) {
            if (matrix[i][0] == 0) {
                cZ = true;
                break;
            }
        }
        
        for (int r = 1; r < matrix.size(); r++) {
            for (int c = 1; c < matrix[0].size(); c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                // make row i 0
                int row = i;
                for (int j = 0; j < matrix[0].size(); j++)
                    matrix[row][j] = 0;
            }
        }
        
        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                // make col i 0
                int col = i;
                for (int j = 0; j < matrix.size(); j++)
                    matrix[j][col] = 0;
            }
        }
        
        if (rZ) {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        
        if (cZ) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};

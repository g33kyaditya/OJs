class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        int R = matrix.size()-1;
        int C = matrix[0].size()-1;
        
        int r = 0, c = C;
        while (r <= R && c >= 0) {
            if (target < matrix[r][c])
                c--;
            else if (target > matrix[r][c])
                r++;
            else
                return true;
        }
        
        return false;
     
    }
};

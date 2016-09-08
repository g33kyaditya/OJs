class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int c = matrix[0].size() - 1;
        int R = 0;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][c] >= target) {
                R = i;
                break;
            }
        }
        
        int low = 0;
        int high = c;
        while (low <= high) {
            int mid = (low + high)/2;
            if (matrix[R][mid] == target)
                return true;
            else if (matrix[R][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

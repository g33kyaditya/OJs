class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int num = 1;
        vector<vector<int>> arr(n, vector<int>(n));
        int rL = 0, cL = 0;
        int rH = n-1, cH = n-1;
        int dir = 0;
        
        while (rL <= rH && cL <= cH) {
            
            if (dir == 0) {
                
                for (int i = cL; i <= cH; i++) {
                    arr[rL][i] = num;
                    num++;
                }
                dir = 1;
                rL++;
            }
            
            if (dir == 1) {
                
                for (int i = rL; i <= rH; i++) {
                    arr[i][cH] = num;
                    num++;
                }
                dir = 2;
                cH--;
            }
            
            if (dir == 2) {
                
                for (int i = cH; i >= cL; i--) {
                    arr[rH][i] = num;
                    num++;
                }
                dir = 3;
                rH--;
            }
            
            if (dir == 3) {
                
                for (int i = rH; i >= rL; i--) {
                    arr[i][cL] = num;
                    num++;
                }
                dir = 0;
                cL++;
            }
            
        }
        
        return arr;
    }
};

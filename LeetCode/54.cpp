class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    vector<int> result;
    if (matrix.empty())
        return result;
    
    vector<vector<int>> A = matrix;
    
	int rL = 0, cL = 0;
	int rH = A.size() - 1;
	int cH = A[0].size()-1;
	int dir = 0;
	
	while (rL <= rH && cL <= cH) {
	    
	    if (dir == 0) {
	        for (int i = cL; i <= cH; i++) {
	            result.push_back(A[rL][i]);
	            dir = 1;
	        }
	        rL++;
	    }
	    
	    if (dir == 1) {
	        for (int i = rL; i <= rH; i++) {
	            result.push_back(A[i][cH]);
	            dir = 2;
	        }
	    
	        cH--;
	    }
	    
	    
	    if (dir == 2) {
	        for (int i = cH; i >= cL; i--) {
	            result.push_back(A[rH][i]);
	            dir = 3;   
	        }
	        rH--;
	    }
	    
	    if (dir == 3) {
	        for (int i = rH; i >=  rL; i--) {
	            result.push_back(A[i][cL]);
	            dir = 0;
	        }
	        cL++;
	    }
	}
	
	return result;        
    }
};

bool isBadVersion(int version);  
  
class Solution {  
public:  
    int firstBadVersion(int n) {  
        int start = 1;  
        int end = n;  
        int middle;
        int last = n;
        while(start <= end){  
            middle = start + (end - start)/2;
            if(isBadVersion(middle)) {
               if (middle < last)
                    last = middle;
                end = middle - 1;
            }
            else start = middle + 1;  
        }  
        return last;
    }  
};  

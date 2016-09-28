class Solution {
public:
    bool isPowerOfFour(int num) {
        
        if (num == 0)
            return false;
        
        if (num == 1)
            return true;
        
        bool alreadySet = false;
        int count = 0;
        while (num != 0) {
            if (alreadySet && num&1)
                return false;
            
            if (num&(1)) {
                alreadySet = true;
            }
            else
                count++;
            
            num = num >> 1;
        }
        
        if (count%2 == 0 && alreadySet)
            return true;
        else
            return false;
           
    }
};

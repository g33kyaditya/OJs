class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int po = 1;
        while (x/po >= 10) {
            po = po*10;
        }
        
        while (x != 0) {
            int rem = x%10;
            int first = x/po;
            if (rem != first)
                return false;

            x = (x%po)/10;
            po = po/100;
        }
        return true;
    }
};

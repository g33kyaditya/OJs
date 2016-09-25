class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if (num == 0)
            return false;
        
        long long int low = 1;
        long long int high = num;
        long long int mid = 0;
        long long int last = mid;
        
        while (low <= high) {
            mid = (low + high)/2;
            if (mid*mid == num)
                return true;
            else if (mid*mid < num) {
                last = mid;
                low = mid+1;
            }
            else
                high = mid - 1;
        }
        
        if (last*last != num)
            return false;
        
        return true;
    }
};

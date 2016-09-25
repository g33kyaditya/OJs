class Solution {
public:
    int mySqrt(int x) {
        
        long long int low = 1;
        long long int high = x;
        long long int mid = 0;
        long long int last = 0;
        if (x < 0)
            return INT_MIN;

        while (low <= high) {
            mid = (long long)(low + high)/2;
            if (mid*mid == x) {
                return mid;
            }
            else if (mid*mid < x) {
                last = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return last;
    }
};

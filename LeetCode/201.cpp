class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bits = 0;
        while (1) {
            if (n > m)
                bits++;
            else {
                return m << bits;
            }
            
            m >>= 1;
            n >>= 1;
        }
        return m;
    }
};

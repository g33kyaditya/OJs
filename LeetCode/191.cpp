class Solution {
public:
    int hammingWeight(uint32_t n) {
        int a = 32;
        int count = 0;
        while(a--) {
            if (n&(01))
                count++;
            
            n = n >> 1;
        }
        return count;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        long long int i = 5;
        long long int count = 0;
        while (i <= n) {
            count = count + n/i;
            i = i*5;
        }
        return count;
    }
};

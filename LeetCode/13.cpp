class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int fD, sD;
        if (s.length() == 1) {
            int ret = check(s[0]);
            return ret;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            fD = check(s[i]);
            sD = check(s[i+1]);
            if (fD < sD) {
                fD = fD*(-1);
            }
            ans = ans + fD;
        }
        ans = ans + sD;
        return ans;
    }
    
    int check(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

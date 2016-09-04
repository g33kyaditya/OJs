class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            int st = s[i] - 'A' + 1;
            num = num*26 + st;
        }
        
        return num;
    }
};

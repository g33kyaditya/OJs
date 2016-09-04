class Solution {
public:
    string convertToTitle(int n) {
        
        string ans = "";
        char st;
        while (n > 0) {
            int rem = n%26;
            if (rem == 0) {
                st = 'Z';
                ans = ans + st;
                n = n/26 - 1;
                continue;
            }
            
            st = rem  + 'A' - 1;
            ans = ans + st;
            n = n/26;
        }
        
    std::reverse(ans.begin(), ans.end());
    return ans;
    }
};

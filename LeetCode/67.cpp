class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() && b.empty())
            return to_string(0);
        string ans = "";
        int carry = 0;
        int i, j;
        int sum = 0;
        for (i = a.length()-1, j = b.length()-1; i>=0 && j>=0; i--, j--) {
            sum = a[i] - '0' + b[j] - '0' + carry;
            
            if (sum == 1) {
                carry = 0;
            }
            
            if (sum == 2) {
                sum = 0;
                carry = 1;
            }
            
            if (sum == 3) {
                sum = 1;
                carry = 1;
            }
            
            ans = ans + std::to_string(sum);
        }
        
        if (i >= 0) {
            while (i >= 0) {
                sum = a[i] - '0' + carry;
                
                if (sum == 1) {
                    carry = 0;
                }
                
                if (sum == 2) {
                    sum = 0;
                    carry = 1;
                }
            
                ans = ans + std::to_string(sum);
                i--;
            }
        }
        
        if (j >= 0) {
            while (j >= 0) {
                sum = b[j] - '0' + carry;
                
                if (sum == 1) {
                    carry = 0;
                }
                
                if (sum == 2) {
                    sum = 0;
                    carry = 1;
                }
                ans = ans + std::to_string(sum);
                j--;
            }
        }
        
        if (carry != 0)
            ans = ans + std::to_string(carry);
            
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

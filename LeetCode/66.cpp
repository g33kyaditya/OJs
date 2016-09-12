class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> ans;
        if (digits.size() == 0) {
            ans.push_back(1);
            return ans;
        }
        
        int carry = 0;
        for (int i = digits.size()-1; i >= 0; i--) {
            int t = digits[i] + carry;
            if (i == digits.size()-1)
                t++;
            
            ans.push_back(t%10);
            carry = t/10;
        }
        if (carry != 0)
            ans.push_back(carry);
    
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

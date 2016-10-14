class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        
        if (denominator == 0)
            return std::to_string(INT_MAX);
        
        if (numerator == 0)
            return "0";
        
        long num = numerator;
        long den = denominator;
        
        bool negative = false;
        if ((num < 0) ^ (den < 0)) {
            negative = true;
            if (num < 0)
                num = num * (-1);
            else
                den = den * (-1);
        }
        
        long beforeDecimal = num/den;
        ans = std::to_string(beforeDecimal);
        
        long rem = (num % den) * 10;
        if (rem == 0) {
            if (!negative)
                return ans;
            else {
                ans = "-" + ans;
                return ans;
            }
        }
        
        unordered_map<long, int> m;
        ans = ans + ".";
        
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                int pos = m[rem];
                string left = ans.substr(0, pos);
                string right = ans.substr(pos);
                
                ans = left + "(" + right + ")";
                if (!negative)
                    return ans;
                else {
                    ans = "-" + ans;
                    return ans;
                }
            }
            
            long k = rem / den;
            ans = ans + std::to_string(k);
            m[rem] = ans.length() - 1;
            rem = ( rem % den ) * 10;
        }
        
        if (negative)
            ans = "-" + ans;
        
        return ans;
    }
};

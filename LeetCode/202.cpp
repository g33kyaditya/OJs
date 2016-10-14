class Solution {
public:
    
    int sum(int n) {
        int sum = 0;
        while (n != 0) {
            sum = sum + (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
    
    
    bool isHappy(int n) {
        
        if (n == 1)
            return true;
        
        set<int> s;
        while(s.find(n) == s.end()) {
            s.insert(n);
            n = sum(n);
            
            if (n == 1)
                return true;
        }
        return false;
    }
};

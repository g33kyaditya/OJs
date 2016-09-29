class Solution {
public:
    string countAndSay(int n) {
    
        if (n == 0 || n == 1)
            return "1";
        if (n == 2)
            return "11";
        
        string last = "11";
        string cur = "";
        int count = 0;
        for (int i = 3; i <= n; i++) {
            last = last + "%";
            cur = "";
            count = 1;
            for (int j = 1; j < last.length(); j++) {
                if (last[j] == last[j-1])
                    count++;
                else {
                    cur = cur + to_string(count);
                    cur = cur + last[j-1];
                    count = 1;
                }
            }
            last = cur;
        }
        
        return cur;
        
        
    }
};

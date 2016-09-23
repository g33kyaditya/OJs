class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if (s.empty())
            return true;
        
        int i = 0;
        int j = 0;
        bool ans = false;
        while (i < s.length() && j < t.length()) {
            if (s[i] != t[j]) {
                j++;
                continue;
            }

            int nextS = i+1;
            int nextJ = j+1;
            while (nextS < s.length() && nextJ < t.length()) {
                if (s[nextS] == t[nextJ]) {
                    nextS++;
                    nextJ++;
                }
                else
                    nextJ++;
            }
            if (nextS == s.length()) {
                return true;
            }
            i++;
            j++;
        }
        
        return ans;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        
        string cur = "";
        vector<char> v;
        for (int i = 0; i < s.length(); i++) {
            if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9'))
                v.push_back(std::tolower(s[i]));
        }
        int lo = 0, hi = v.size()-1; 
        for(lo,hi; lo <= hi; lo++, hi--) {
            if (v[lo] == v[hi])
                continue;
            else
                return false;
        }
        return true;
    }
};

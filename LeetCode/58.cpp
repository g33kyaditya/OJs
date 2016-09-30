class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count = 0;
        string str;
        int last = s.length();
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == ' ')
                last--;
            else
                break;
        }
        str = s.substr(0, last);
        for (int i = str.length()-1; i >=0; i--) {
            if (s[i] == ' ') {
                count = str.length()-1 - i;
                return count;
            }
            else if (i == 0) {
                count = str.length();
                return count;
            }
        }
        return count;
    }
};

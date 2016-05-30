class Solution {
public:
    string reverseString(string s) {
        int j = 0;
        rev = "";
        for (int i = s.length()-1; i >= 0; i--)
            rev = rev + s[i];
        return rev;
    }
private:
    string rev;
};

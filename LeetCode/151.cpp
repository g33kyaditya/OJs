class Solution {
public:
    void reverseWords(string &s) {
    
    string A = s;
    vector<string> v;
    string str = "";
    if (s.empty()) {
        return;
    }
    for (int i = 0; i < A.length(); i++) {
        if (A[i] != ' ')
            str = str + A[i];
        else {
            if (str != "")
                v.push_back(str);
            
            str = "";
        }
    }
    if (str != "" && str != " ")
        v.push_back(str);
    
    A = "";
    if (v.empty()) {
        s = "";
        return;
    }
    for (int i = v.size()-1; i > 0; i--) {
        A = A + v[i];
        A = A + " ";
    }
        A = A + v[0];
        s = A;
    }    
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        bool chars[126];
        memset(chars, false, sizeof(chars));
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] != t[i])
                    return false;
            }
            else {
                if (chars[t[i]]) {
                    auto it = m.begin();
                    for (it; it != m.end(); it++) {
                        if (it->second == t[i] && it->first != s[i])
                            return false;
                    }
                }
                m[s[i]] = t[i];
                chars[t[i]] = true;
            }
        }
        return true;
    }
};

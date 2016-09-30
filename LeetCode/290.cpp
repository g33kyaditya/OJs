class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        if (pattern.empty() || str.empty())
            return false;
        
        vector<string> strings;
        str = str + " ";
        int last = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                strings.push_back(str.substr(last, i-last));
                last = i+1;
            }
        }
        if (strings.empty())
            return false;
        
        //strings.push_back(str.substr(last, str.length()-last));
        
        unordered_map<char, string> m;
        unordered_map<string, char> alt;
        
        if (pattern.length() != strings.size())
            return false;
        
        int index = 0;
        for (int i = 0; i < pattern.length(); i++) {
            if (m.find(pattern[i]) == m.end() && alt.find(strings[index]) == alt.end()) {
                m[pattern[i]] = strings[index];
                alt[strings[index]] = pattern[i];
            }
            else {
                if (strings[index] != m[pattern[i]] || alt[strings[index]] != pattern[i])
                    return false;
            }
            index++;
        }
        
        return true;
    }
};

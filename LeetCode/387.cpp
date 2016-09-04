class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, pair<int,int>>m;
        m.clear();
        for (int i = 0; i < s.length(); i++) {
            m[s[i]].first = i;
            m[s[i]].second++;
        }
        int min = 1000000000;
        unordered_map<char, pair<int, int>>::iterator it = m.begin();
        for(it; it != m.end(); it++) {
            pair<int, int> cur = it->second;
            if (cur.second == 1) {
                if (cur.first < min)
                    min = cur.first;
            }
        }
        
        if (min == 1000000000)
            return -1;
        
        return min;
    }
};

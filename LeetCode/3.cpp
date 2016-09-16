class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        bool visited[130];
        
        if (s.empty())
            return 0;
        
        /*if (s.length() == 1)
            return 1;*/
        
        int lowest;
        int curr;
        int ans = INT_MIN;
        for (int i = 0; i < s.length(); i++) {
            lowest = i;
            curr = 0;
            for (int i = 0; i < 130; i++)
            visited[i] = false;
            
            for (int j = lowest; j < s.length(); j++) {
                if (!visited[s[j]]) {
                    curr++;
                    visited[s[j]] = true;
                }
                else {
                    break;
                }
                if (curr > ans)
                    ans = curr;
            }
            
        }
        
        return ans;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[126] = {0}, arr2[126] = {0};
        for (int i = 0; i < s.length(); i++)
            arr1[s[i]]++;
        
        for (int j = 0; j < t.length(); j++)
            arr2[t[j]]++;
        
        for (int i = 65; i < 126; i++) {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
};

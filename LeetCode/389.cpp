class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[130];
        int arr2[130];
        
        memset(arr, 0, sizeof(arr));
        memset(arr2, 0, sizeof(arr2));
        
        for (int i = 0; i < s.length(); i++)
            arr[s[i]]++;
        
        for (int i = 0; i < t.length(); i++)
            arr2[t[i]]++;
        
        char ret = '@';
        for (int i = 97; i < 123; i++) {
            if (arr[i] < arr2[i]) {
                ret = char('a' + i-97);
                return ret;
            }
        }
        return ret;
    }
};

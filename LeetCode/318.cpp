class Solution {
public:
    bool common(string a, string b) {
        bool arr[126] = {false};
        for (int i = 0; i < a.length(); i++)
            arr[a[i]] = true;
        for (int j = 0; j < b.length(); j++) {
            if (arr[b[j]])
                return true;
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int ans = 0;
        if (words.empty())
            return 0;
        for (int i = 0; i < words.size()-1; i++) {
            int len1 = words[i].length();
            for (int j = i+1; j < words.size(); j++) {
                int len2 = words[j].length();
                if (len1*len2 > ans && !common(words[i], words[j]))
                    ans = len1*len2;
            }
        }
        return ans;
    }
};

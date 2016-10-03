class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if (n == 0)
            return ans;

        for (int i = 1; i < pow(2,n); i++) {
            ans.push_back(i ^ (i/2));
        }
        return ans;
    }
};

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
#define max(x,y) ((x)>(y) ? (x) : (y))
int main() {
    string str1,str2;
    cin >> str1;
    cin >> str2;
    int l1 = str1.length();
    int l2 = str2.length();
    vector<vector<int> > dp(l1,vector<int>(l2));
    
    for (int i=1;i<l1;i++) {
        for (int j=1;j<l2;j++) {
            if (str1[i] == str1[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[l1-1][l2-1] << endl;
}

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
string str1,str2;
int l1,l2;
vector<vector<int> > dp(2001,vector<int>(2001));
int foo (int i,int j) {
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    int ret;
    ret = min(foo(i-1,j)+1, foo(i,j-1)+1);
    if (str1[i-1] == str2[j-1])
        ret = min(ret,foo(i-1,j-1));
    else
        ret = min(ret,foo(i-1,j-1)+1);
    
    dp[i][j] = ret;
    return ret;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> str1 >> str2;
        l1 = str1.length();
        l2 = str2.length();
        for (int i=0;i<2001;i++) {
            for (int j=0;j<2001;j++)
                dp[i][j] = -1;
        }
        int ans = foo(l1,l2);
        cout << dp[l1][l2] << endl;
    }
}


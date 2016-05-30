#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX(a,b) (a > b ? a : b)
using namespace std;

int dp[6102][6102];

int LCS(string a, char b[], int l) {
    
    for (int i = 0; i < l+2; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    
    for(int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[l][l];
}

int main() {
    string str;
    int t;
    cin >> t;
    while(t--) {
        cin >> str;
        char rev[str.length()+1];
        
        for (int i = str.length()-1, j = 0; i >=0; i--, j++)
            rev[j] = str[i];
        
        rev[str.length()] = '\0';
        
        int ret = LCS(str, rev, str.length());
        int ans = str.length() - ret;
        cout << ans << "\n";
    
    }
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <bitset>
using namespace std;
int n;
int v[101];
int dp[101][101];
int foo (int i,int j) {
    int sum = 0;
    for (int k=i;k<=j;k++) {
        sum = sum + v[k];
        sum = sum%100;
    }
    return sum;
}

int solve (int i,int j) {
    if (dp[i][j]!=-1)
      return dp[i][j];
    
    if (i == j)
      return 0;
    
    int val = dp[i][j];
    for (int k=i;k+1<=j;k++) {
      int temp = solve(i,k) + solve(k+1,j) + foo(i,k)*foo(k+1,j);
      if (val==-1 || temp<val)
	        val = temp;
      }
      dp[i][j] = val;
      return val;
}
int main() {
    while (cin >> n) {
        for (int i=1;i<=n;i++)
            cin >> v[i];
        
	memset (dp,-1,sizeof dp);
        int ans = solve(1,n);
        cout << ans << endl;
    }
}

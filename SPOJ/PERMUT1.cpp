#include <iostream>
#include <cstring>
using namespace std;
int dp[15][100] ;
int val;
int solve (int i,int j) {

    
    if (j == 0)
        return 1;
    if (i == 0)
	return 0;
    
    if (dp[i][j] != -1) 
        return dp[i][j];
    int val = 0;
    for(int z = 0; z < i && j-z >= 0; z++)
		val += solve(i-1,j-z);
	
   return (dp[i][j] = val);

}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
	
        cin >> n >> k;
	memset(dp,-1,sizeof dp);
        int ans = solve(n,k);
        cout << ans << endl;
    }

}

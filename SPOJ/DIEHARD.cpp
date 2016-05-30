#include <iostream>
#include <cstring>
using namespace std;
#define MAXIMUM(x,y,z) ((x>y)&&(x>z) ? x : ((y>z) ? (y) : (z) ))
int dp[1010][1010];
int status;                 //1->Fire; 2->Air; 3->Water 
int solve (int h,int a,int count,bool f) {
    if (h <= 0)
        return count;
    if (a <= 0)
        return count;
    
    if (dp[h][a]!= -1)
        return dp[h][a];
    
    if (f) {
	dp[h][a] = max(dp[h][a],solve(h+3,a+2,count+1,!f));
    }
    return dp[h][a] = max(dp[h][a], max(solve(h-5,a-10,count+1,!f),solve(h-20,a+5,count+1,!f)));
    
}
int main() {
    int t;
    cin >> t;
    int health,armour;
    while (t--) {
        cin >> health >> armour;
        memset(dp,-1,sizeof (dp));
        bool flag = true;
	int m = solve(health,armour,-1,flag);
	cout << m << endl;
    }
}

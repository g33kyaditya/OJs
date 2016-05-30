#include <iostream>
#include <cstring>
using namespace std;
int v[2005];
int save[2005][2005];
int profit (int day,int start,int last) {
    if (last < start)
        return 0;
    if (save[start][last] != -1)
        return save[start][last];
    
    return (save[start][last] = max(profit(day+1,start+1,last)+v[start]*day,profit(day+1,start,last-1)+v[last]*day));
}
int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> v[i];
    memset(save,-1,sizeof save);
    int ans = profit(1,0,n-1);
    cout << ans << endl;
}

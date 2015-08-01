#include <iostream> 
using namespace std; int main(){int t,n,d[100][100],i,j;cin>>t;while(t--){cin>>n;for(i=0;i<n;i++){for(j=0;j<=i;j++)cin>>d[i][j];}for(i=n-2;i>=0;i--){for(j=0;j<=i;j++)d[i][j]=d[i][j]+max(d[i+1][j],d[i+1][j+1]);}cout<<d[0][0]<<endl;}}

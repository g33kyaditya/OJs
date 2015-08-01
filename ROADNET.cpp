#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int road[n+1][n+1];
        bool foo[n+1][n+1];
        memset(foo,true,sizeof foo);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) 
                cin >> road[i][j];
        }
        int dist1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                for (int k=1;k<=n;k++) {
                    if ((road[i][j] == (road[i][k] + road[k][j]))&&(k!=j)&&(k!=i)) {
                        foo[i][j] = false;
                    }
                }
            }
        }

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (foo[i][j] && (i!=j) && (j>i)) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
}

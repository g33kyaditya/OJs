#include <iostream>
#include <cstring>
#define max(x,y) ((x>y) ? (x) : (y))
using namespace std;
int maxDP[100005];
int arr[100005];
int X = -10000000;
int main() {
    int t;
    cin >> t;
    while (t--) {
         int n;
        cin >> n;
        for ( int i=0;i<n;i++) 
            cin >> arr[i];
        maxDP[0] = arr[0];
        X = -100000000;
        int count = 0;
        for ( int i=1;i<n;i++) {
            maxDP[i] = max(maxDP[i-1]+arr[i],arr[i]);
            if (maxDP[i] >= X) {
            X = maxDP[i];
            }
        }
        cout << X << " " ;
    }
}

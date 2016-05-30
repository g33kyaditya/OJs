#include <iostream>
using namespace std;
#define LL long long int
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        LL ans;

        if (n%2 == 0) {
            ans = (n/2);
            LL b = 3*n + 1;
            ans = ans*b;
        }
        else {
            ans = 3*n + 1;
            ans = ans/2;
            ans = ans*n;
        }
        ans = ans%1000007;
        cout << ans << "\n";
    }
}

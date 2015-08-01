#include <iostream>
using namespace std;
inline long long int fact (long long int num) {
    long long int f = 1,i=1;
    if (num == 0)
        return 1;
    while (i <= num) {
        f = f*i;
        i++;
    }
    return f;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        long long int ans = 1;
        if ((n-k) >= (k-1)) {
            for (int i = n-1;n>n-k;i--)
                ans = ans*i;
           long long int val = fact(k-1);
           ans = ans/val;
        }
        else {
            for (int i = n-1;i>k-1;i--)
                ans = ans*i;
            long long int val = fact(n-k);
            ans = ans/val;
        }

        cout << ans << endl;
    }
}

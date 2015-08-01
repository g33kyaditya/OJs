#include <iostream>
using namespace std;
int main() {
    long long int n,val;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n%2 == 0) {
            n = n/2;
            val = (n*((n+1)*(4*n +1)))/2;
        }
        else {
            n = n-1;
            n = n/2;
            val = ((n+1)*(4*n*n + 7*n +2))/2;
        }

        cout << val << endl;
    }
}

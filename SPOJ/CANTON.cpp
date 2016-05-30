#include <iostream>
#include <cmath>
using namespace std;
inline int foo (int n ) {
    return ceil(-0.5+(sqrt((8*n) +1)/2.0));
}
main()
{
    int t;
    cin >> t;
    while (t--) {
        float n;
        cin >> n;
        int p = foo (n);
        long long int x = (p*(p+1))/2;
        long long int diff = x - n;

        if (p%2 ==0) {
            cout << "TERM " << int(n) << " IS " << (p-diff) << "/" << 1+diff << endl; 
        }
        else {
            cout << "TERM " << int(n) << " IS " << 1+diff << "/" << p-diff << endl;
        }
    }
}

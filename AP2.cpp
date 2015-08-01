#include <iostream>
using namespace std;
main()
{
    int t;
    cin >> t;
    while (t--) {
        long long  p,q,r;
        cin >> p;
        cin >> q;
        cin >> r;

        long long n = (r*2)/(p+q);
        long long d = (q-p)/(n-5);
        long long a = p-(2*d);

        cout << n << "\n";
        for (long long i = a,j=0; j <n; i= i+d,j++) 
            cout << i << " ";

        cout << "\n";
    }
}

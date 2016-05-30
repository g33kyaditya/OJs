#include <iostream>
#include <cmath>
using namespace std;
main()
{
    long long int n,count = 0;
    cin >> n;
    for (long long int i = 1;i<=floor(sqrt(n));i++) {
        for (long long int j = i+1;i*j<=n;j++)
            count++;
    }

    cout << count + floor(sqrt(n)) << endl;
}

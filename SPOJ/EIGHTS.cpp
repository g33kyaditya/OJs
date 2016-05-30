#include <iostream>
#include <cstdio>
using namespace std;
main()
{
    int t;
    unsigned long long int k;
    scanf("%d",&t);
    while (t--) {
        scanf ("%lld",&k);
        unsigned long long int val=192;

        val = 192 + (k-1)*250;

        printf("%lld\n",val);
    }
}

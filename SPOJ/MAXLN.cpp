#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t, i = 0;
    cin >> t;
    while(i < t)
    {
            long long int r;
            cin >> r;
            double s;
            s = double(4*r*r) + 0.25;
            printf("Case %d: %.2lf\n",++i,s);
    }
}

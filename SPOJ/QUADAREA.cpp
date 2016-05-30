#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int main() {
    int t;
    cin >> t;
    double a,b,c,d,s;
    while (t--) {
        cin >> a >> b >> c >> d;
        s = (a+b+c+d)/2;

        double ans = (s-a) * (s-b) * (s-c) * (s-d);
        ans = sqrt(ans);
        printf("%.2lf\n", ans);
    }
}

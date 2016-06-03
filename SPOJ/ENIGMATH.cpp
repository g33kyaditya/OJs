#include <iostream>
using namespace std;

#define SMALL(X,Y) ( (X < Y) ? (X) : (Y) )

long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int a,b;
        cin >> a >> b;
        long long int g = gcd(a,b);
        
        long long int lcm = (a/g)*b;
        cout << lcm/a << " " << lcm/b << "\n";
    }
}

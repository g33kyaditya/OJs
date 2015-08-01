#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double n;
    while (cin >> n) {
        if (n == -1)
            return 0;
        
        n = (n-1)/3;
        double foo = 1+sqrt(1 + 4*n);
        foo = foo/2;

        int bar = int(foo);

        if (foo - bar == 0.000000)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
}

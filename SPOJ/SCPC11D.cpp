#include <iostream>
using namespace std;
int main() {
    while (1) {
        int x,y,z;
        cin >> x >> y >> z;
        if (x == y && y == z && x == 0)
            return 0;

        long long a,b,c;
        if (x >y && x > z) {
            c = x;
            a = z;
            b = y;
        }
        else if (y > z) {
            c = y;
            a = x;
            b = z;
        }
        else {
            c = z;
            a = x;
            b = y;
        }
        if ((a*a) + (b*b) == (c*c)) 
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
}

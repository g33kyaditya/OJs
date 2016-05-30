#include <iostream>
using namespace std;
int main() {
    int a,b;
    while (1) {
        cin >> a >> b;
        if (a == b && a==-1)
            return 0;
        if (a == 1 || b == 1) 
            cout << a << "+" << b << "=" << a+b << endl;
        else
            cout << a <<"+" <<b << "!=" << a+b << endl;
    }
}

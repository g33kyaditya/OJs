#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;cin >> t;
    while (t--) {
        string str;unsigned long long int b;cin >> str >> b;int a = str[str.length()-1]-'0';int a4 = (a*a*a*a)%10;int a3 = (a*a*a)%10;int a2 = (a*a)%10;int a1 = a%10;int rem = b%4;
        if (a==0) 
            cout << "0" << endl;
        else if (b == 0)
            cout << "1" << endl;
        else if (rem == 0) 
            cout << a4 << endl;
        else if (rem == 1)
            cout << a1 << endl;
        else if (rem == 2)
            cout << a2 << endl;
        else if (rem == 3)
            cout << a3 << endl;
    }
}

#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        unsigned long long int sum = 0;
        cin >> n;
        int foo;
        int temp=n;
        for (int i=1;i<temp;i++) {
            if ((n%i ==0) && (i!=1)) { 
                foo = n/i;
                temp = foo; 
            }
            if (n%i == 0) 
                sum = sum+i+(n/i);
            if (i == 1)
                sum = sum-n;
            if ((i*i) == n)
                sum = sum-(n/i);
        }
        cout << sum << endl;
    }
}

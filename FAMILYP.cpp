#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        int ans;
        int temp = n;
        ans = ceil((sqrt(1+8*n)/2 -0.5));
        
        cout << "TERM " << temp << " IS " << char('A' + (ans-1)%26) << endl;
    }
}

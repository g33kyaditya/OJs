#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        double n;
        cin >> n;
        cout << int(ceil(n/2)) << "\n";
    }
}

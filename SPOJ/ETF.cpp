#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int result = n;
        for (int p = 2; p <= sqrt(n); p++) {
            if (n%p == 0) 
                result = result - result/p;
            
            while (n%p == 0)
                n = n/p; 
        }

        if (n > 1)
            result = result - result/n;

        cout << result << "\n";
    }

}

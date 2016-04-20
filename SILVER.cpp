#include <iostream>
using namespace std;
int main() {
    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            return 0;
        int count = 0;
        while(n > 1) {
            count++;
            n = n/2;
        }

        cout << count << "\n";
    }
}

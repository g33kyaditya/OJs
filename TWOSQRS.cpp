#include <iostream>
#include <cmath>
#define LL long long
using namespace std;
bool isSquare (LL int num) {
    LL temp = sqrt (num);
    if (num - (temp*temp) == 0)
        return true;
    else
        return false;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        LL num;
        cin >> num;
        bool ans = false;
            LL a;
            a = sqrt (num);
            LL diff;
            for (LL i = a; i>=0;i--) {
                diff = num - (i*i);
                if (isSquare(diff)) {
                    ans = true;
                   // cout << "diff = " << diff << endl;
                   // cout << " a = " << i << endl;
                    break;
                }
                else
                    ans = false;
            }
        

        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

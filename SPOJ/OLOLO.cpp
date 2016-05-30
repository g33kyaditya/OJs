#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    int ans, a;
    cin >> n;
    cin >> a;
    ans = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        ans = ans ^ a;
    }

    cout << ans << "\n";
}

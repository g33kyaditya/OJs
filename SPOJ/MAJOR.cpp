#include <iostream>
#include <cstring>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int freq[2005];
        memset(freq, 0, sizeof(freq));
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            freq[num+1000]++;
        }
        bool ans = false;
        for (int i = 0; i < 2005; i++) {
            if (freq[i] > (n/2)) {
                cout << "YES " << i-1000 << "\n";
                ans = true;
                break;
            }
        }

        if (!ans)
            cout << "NO\n";

    }
}

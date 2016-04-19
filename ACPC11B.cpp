#include <iostream>
using namespace std;
int main() {
    long long int t;
    cin >> t;
    while(t--) {
        long long int n1, n2;
        cin >> n1;
        long long int a[n1];
        for (long long int i = 0; i < n1; i++)
            cin >> a[i];
        cin >> n2;
        long long int b[n2];
        for (long long int i = 0; i < n2; i++)
            cin >> b[i];

        int ans = 100000000, diff;
        for (long long int i = 0; i < n1; i++) {
            for (long long int j = 0; j < n2; j++) {
                    
                if (a[i] > b[j])
                    diff = a[i] - b[j];
                else
                    diff = b[j] - a[i];
            
                if (diff < ans)
                    ans = diff;
            }

        }
        cout << ans << "\n";
    }   
}

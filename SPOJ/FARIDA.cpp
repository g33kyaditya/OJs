#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        c++;
        int n;
        cin >> n;
        long long int arr[n+2];
        
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        
        long long int dp[n+2];
        dp[0] = 0;
        dp[1] = arr[1];

        for (int i = 2; i <= n; i++) {
            
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        cout << "Case " << c << ": " << dp[n] << "\n";
    }
}

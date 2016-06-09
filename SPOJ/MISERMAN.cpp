#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int dp[n][m], cost[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        dp[0][i] = cost[0][i];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j-1 < 0) {
                dp[i][j] = std::min(dp[i-1][j], dp[i-1][j+1]) + cost[i][j];
            }
            
            else if (j+1 > m) {
                    dp[i][j] = std::min(dp[i-1][j], dp[i-1][j-1]) + cost[i][j];
            }
            
            else {
                dp[i][j] = std::min(dp[i-1][j+1], std::min(dp[i-1][j], dp[i-1][j-1])) + cost[i][j];
            }
        }
    }
    
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << dp[i][j] << "  ";
        
        cout << "\n";
    }*/
    int smallest = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (dp[n-1][i] <= smallest)
            smallest = dp[n-1][i];
    }

    cout << smallest << "\n";
}

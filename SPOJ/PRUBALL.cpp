#include <iostream>
#include <climits>
#include <cstring>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        
        int decimal, eggs, floors;
        cin >> decimal >> eggs >> floors;

        int dp[eggs+1][floors+1];
        memset(dp, 0, sizeof(dp));
        for (int floor = 0; floor <= floors; floor++)
            dp[1][floor] = floor;
        
        for (int egg = 2; egg <= eggs; egg++) {
            for (int floor = 1; floor <= floors; floor++) {
                if (egg > floor)
                    dp[egg][floor] = dp[egg-1][floor];
                else {
                    int min = INT_MAX;
                    int cur;
                    for (int k = 1; k <= floor; k++) {
                        cur = 1 + max(dp[egg-1][k-1], dp[egg][floor-k]);
                        if (cur < min)
                            min = cur;
                    }
                    dp[egg][floor] = min;
                }
            }
        }
        
        cout << decimal << "  " << dp[eggs][floors] << "\n";
    }
}

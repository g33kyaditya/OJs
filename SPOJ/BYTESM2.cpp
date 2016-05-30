#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#define MAX(x,y) ((x>y) ? (x) : (y))
#define LL long long int
using namespace std;
int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int h,w;
        cin >> h >> w;
        int arr[h][w];
        int dp[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cin >> arr[i][j];
        }
        
        for (int i = 0; i < w; i++) 
            dp[0][i] = arr[0][i];


        for (int i = 1; i < h; i++) {
            for (int j = 0; j < w; j++) {
                
                if (j-1 >= 0 && j+1 < w) {
                    int k = MAX(dp[i-1][j-1], dp[i-1][j+1]);
                    dp[i][j] = MAX(dp[i-1][j], k) + arr[i][j];
                }
                else if (j-1 >= 0) {
                    dp[i][j] = MAX(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
                }
                else if (j+1 < w) {
                    dp[i][j] = MAX(dp[i-1][j], dp[i-1][j+1]) + arr[i][j];
                }
                else
                    dp[i][j] = dp[i-1][j] + arr[i][j];
            }
        }
        int max = -1000000000;
        
        for (int i = 0; i < w; i++) {
            if (dp[h-1][i] > max)
                max = dp[h-1][i];
        }

        cout << max << "\n";
    }
}

#include <iostream>
#include <climits>

#define MAX_VAL 999999999

#define MIN(a,b) (a < b ? a : b)

int dp[10005];
using namespace std;
int main() {
    
    int t;
    cin >> t;
    int empty, filled;
    while (t--) {
        cin >> empty >> filled;
        int n;
        cin >> n;
        
        int values[n], weights[n];
        for (int i = 0; i < n; i++)
            cin >> values[i] >> weights[i];
        
        int capacity = filled - empty;
        for (int i = 0; i < 10005; i++)
            dp[i] = MAX_VAL;
        
        dp[0] = 0;
        for (int wt = 1; wt <= capacity; wt++) {
            
            for (int coinIndex = 0; coinIndex < n; coinIndex++) {
                if (weights[coinIndex] <= wt) {
                    dp[wt] = MIN(dp[wt], dp[wt-weights[coinIndex]] + values[coinIndex]);   
                }
            }
        }
        
        if (dp[capacity] == MAX_VAL) {
            cout << "This is impossible.\n";
        }
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[capacity] << ".\n";
    }
    
}


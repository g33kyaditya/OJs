#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
    while (1) {
        int totalBudget,totalParties;
        cin >> totalBudget >> totalParties;

        if (totalBudget == totalParties && totalBudget == 0)
            return 0;

        vector<int> fee(totalParties);
        vector<int> fun(totalParties);

        for (int i=0;i<totalParties;i++)
            cin >> fee[i] >> fun[i] ;

        vector<vector<int> > dp(totalParties+1,vector<int>(totalBudget+1));

        int totalFee = 0;
        bool keep[totalParties+1][totalBudget+1];
        for (int i=1;i<=totalParties;i++) {
            for (int j=0;j<=totalBudget;j++) {
                
                if (fee[i-1] <= j) {
                    dp[i][j] = max (dp[i-1][j], fun[i-1] + dp[i-1][j-fee[i-1]]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int best = dp[totalParties][totalBudget],w;
        for (w = totalBudget;w;w--) {
            if (dp[totalParties][w] < best) 
                break;
        }
        cout << w+1 << " " << dp[totalParties][totalBudget] << endl;
    }
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#define min(a,b) ( (a<b) ? (a) : (b) )
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int empty,filled;
        cin >> empty >> filled;

        int capacity = filled-empty;
        int n;
        cin >> n;
        int weights[n],values[n];
        int dp[capacity+1];
        
        
        for (int i=0;i<n;i++) 
            cin >> values[i] >> weights[i];
        
        int myWeight=0;
        int ans = 10000000;
        
        dp[0] = 0;
        for (int i=0;i<=capacity;i++) {
            for (int j=0; j< n; j++) {
                if (i >= weights[j] )
                    ans = min(dp[i-weights[j]],ans);
                    myWeight += weights[j];
            }

            dp[i] = ans;
        }

        if (myWeight == capacity) 
            cout << "The minimum amount of money in the piggy-bank is " << dp[capacity] << "." << endl;
        else
            cout << "This is impossible." << endl;
    }
}

#include <iostream>
#include <vector>

#define max(a,b) ((a > b) ? (a) : (b))  
using namespace std;
int main() {
    
    int totalCapacity,itemCount;
    cin >> totalCapacity >> itemCount;

    int dp[itemCount+1][totalCapacity+1];
    
    for (int i=0;i<=itemCount;i++) {
    	for (int j=0;j<=totalCapacity;j++)
    		dp[i][j] = 0;
    }
    
    int values[itemCount],weights[totalCapacity];
    for (int i=0;i<itemCount;i++) 
        cin >> weights[i] >> values[i];
    
    for (int i=1;i<=itemCount;i++) {
        for (int j=0;j<=totalCapacity;j++) {
        	
        	dp[i][j] = dp[i-1][j];
        	if (weights[i-1] <= j)
        		dp[i][j] = max(dp[i-1][j],values[i-1]+dp[i-1][j-weights[i-1]]);       
        } 
    }
    cout << dp[itemCount][totalCapacity] << endl;
}

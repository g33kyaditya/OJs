#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n;
    while(cin >> n) {
    int arr[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];
    int dp[n];
    if (n == 1) {
	cout << "1" << endl;
	continue;
    }
    for (int i=0;i<n;i++)
	dp[i] = 1;
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j]+1)
                dp[i] = 1+dp[j];
        }
    }
    int max = -1;
    for (int i=0;i<n;i++) {
        if (dp[i] > max)
            max = dp[i];
    }
    cout << max << endl;
}}

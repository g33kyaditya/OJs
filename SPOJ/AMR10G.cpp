#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        
        int n,k;
        cin >> n >> k;
        long long int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort(arr, arr+n);
        long long int md = INT_MAX;
        long long int diff;
        for (int i = 0; i < n-k+1; i++) {
            
            diff = arr[i+k-1] - arr[i];
            if (diff < md)
                md = diff;
        }

        cout << md << "\n";
    }
}

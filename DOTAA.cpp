#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n;
    int m;
    int d;
    while(t--) {
        cin >> n >> m >> d;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool ans = true;
        int count = 0;
        
        for (int j = 0; j < n; j++) {
            
            while (arr[j] > d) {
                arr[j] = arr[j] - d;
                count++;
            }
            
        }

        if (count >= m)
            ans = true;
        else
            ans = false;
        
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }
}

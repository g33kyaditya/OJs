#include <iostream>
#include <cstring>
using namespace std;

int arr[300005];
int visited[300005];

int main() {
    ios_base::sync_with_stdio(false);
    
    memset(visited, 0, sizeof(visited)); 
    long long int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    long long int sum = 0, ans = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        
        if (ans < sum && sum < m)
            ans = sum;
                
        sum = sum + arr[i];
        
        if (sum == m) {
            ans = sum;
            break;
        }
        else {
            while (sum > m) {
                sum = sum - arr[start];
                
                if (sum == m) {
                    ans = sum;
                    break;
                    
                }
                start++;
            }
        }
        
    }

    cout << ans << "\n";
}

#include <iostream>
using namespace std;
long long int foo(int n, int m){
    if(m > n-m) m = n - m;
    
    long long int ans=1;
    
    for(int i = 0; i < m; i++) 
        ans = ans*(n-i)/(i+1);
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    long long int ans;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        ans = foo(n-1, k-1);
        cout << ans << endl;
    }
}

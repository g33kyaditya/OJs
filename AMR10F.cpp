#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        float a,n,d;
        cin >> n >> a >> d;
        float ans = (n/2)*(2*a + (n-1)*d); 
        cout << ans << endl;
    }
}

#include <iostream>
#include <map>
using namespace std;
map<int,unsigned long long> memo;
#define ULL unsigned long long
ULL max (ULL x, ULL y) {
    return x>y?x:y;
}
ULL foo (ULL n) {
    if (n < 12)
        return n;
    
    else if (memo[n] != 0)
        return memo[n];
    
    else {
        ULL ret;
        ret = foo (n/2) + foo (n/3) + foo (n/4);
        memo[n] = ret;
        return ret;
    }
}
int main() {
    ULL n;
    while (cin >> n) {
        ULL ans = max (n,(foo(n/2)+foo(n/3)+foo(n/4)));
        cout << ans << endl;
    }
}

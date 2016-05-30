#include <iostream>
#include <cmath>
using namespace std;
long solve(long num) {
    long f = 1;
    while (f*2 <= num) {
        f = f*2;
    }
    return f;
}
int main() {
    int x,y,z;
    char ch;
    string str;
    while (1) {
        cin >> str;
        if (str == "00e0")
            return 0;
        x = str[0]-'0';
        y = str[1]-'0';
        z = str[3]-'0';
        long num;
        num = x*10 + y;
        while(z--) {
            num = num*10;
        }
        long foo = solve(num);
        long ans = 1 + (num-foo)*2;
        cout << ans << endl;
    } 
}

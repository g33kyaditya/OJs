#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

long int gcd(long int a,long int b){
    if (b == 0)
            return a;
    else
            return gcd(b,a%b);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b;
        scanf("%d %d", &a, &b);
        
        int ret = gcd(a,b);
        int count = 0;
        for (int i = 1; i <= sqrt(ret); i++) {
            if (ret%i == 0) {
                count += 2;
                
                if (i == ret/i)
                    count--;
            }
        }
        printf("%d\n", count);
    }
}

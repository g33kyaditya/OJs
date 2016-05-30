#include <iostream>
using namespace std;
int deg[1000];
int n;
inline long long int f(int a){
long long int ans=0;
for (int i=n;i>0;--i)
   ans=(ans+deg[i])*a;
ans+=deg[0];
return ans;
}
int main() {
    int c = 0;
    while (cin >> n) {
        if (n == -1)
            return 0;
        c++;
        long long int ans;
        
        for (int i=n;i>=0;i--)    
            cin >> deg[i];
        int k;
        cin >> k;
        int points[k];
        for (int i=0;i<k;i++)
            cin >> points[i];

        int x;
        cout << "Case " << c << ":" << endl;
        for (int i=0;i<k;i++) {
            x = points[i];
            cout << f(x) << endl;
        }
    }
}


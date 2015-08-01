#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>
#include <algorithm>
#define max(x,y) ((x>y) ? (x) : (y))
using namespace std;
int main() {
    
    int t;
    cin >> t;
    while (t--) {
        int h,w;
        cin >> h >> w;
        vector<vector <int> > v(h+1,vector<int>(w+1));
        for (int i=1; i<=h; i++) {
            for (int j=1; j<=w; j++) 
                cin >> v[i][j];
        }
        vector<vector<int> > ans(h+1,vector<int>(w+1));
        for (int i=1;i<=h;i++) {
            for (int j=1;j<=w;j++) {
                ans[i][j] = v[i][j] + max (ans[i-1][j],((j==w-1) ? ans[i-1][j+1] : ans[i-1][j-1]));
            }
        }

        cout << ans[h][w] << endl;


    }
}

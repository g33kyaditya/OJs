#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    int q = 0;
    while (t--) {
        q++;
        pair<string,int> arr[10];
        int max = -1;
        bool flag[10];
        
        for (int i=0;i<10;i++) {
            cin >> arr[i].first >> arr[i].second;
            flag[i] = false;
            if (arr[i].second >= max)
                max = arr[i].second;
        }
        for (int i=0;i<10;i++) {
            if (arr[i].second == max) 
                flag[i] = true;
        }
        bool ok = false;
        for (int i=0;i<10;i++) {
            if (flag[i] == true ) {
                if (ok == false) {
                    cout << "Case #" << q << ":" << endl;
                    ok = true;
                }
                cout << arr[i].first << endl;
            }
        }
    }
}

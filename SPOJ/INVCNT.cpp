#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
main() {
    int t;
    cin >> t;
    cout << endl;
    while(t--) {
        int n;
        cin >> n;
     
        vector<int> v(n);
        int val;
        for (int i=0;i<n;i++) {
            cin >> v[i];
        }
        cout << endl;
        long int count = 0;
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                if (v[i] > v[j])
                    count++;
            }
        }

        cout << count << endl;
    }
}

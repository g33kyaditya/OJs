#include <iostream>
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int count = 0;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        	count = count + arr[i]/(i+1);
        }
        if (count%2 ==0)
            cout << "BOB" << endl;
        else
            cout << "ALICE" << endl;
    }
}

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n,k,s;
    cin >> n >> k >> s;
    int arr[n];
    for (int i=0;i<n;i++) 
        cin >> arr[i];

    sort (arr,arr+n);
    int foo = k*s;
    int count = 0;
    for (int i=n-1;i>=0;i--) {
        foo = foo-arr[i];
        count++;
        if (foo <=0)
            break;
    }
    cout << count << endl;
}

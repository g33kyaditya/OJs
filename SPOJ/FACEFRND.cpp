#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[10005];
    memset(arr, 0, sizeof(arr));
    while (n--) {
        int a, m;
        cin >> a >> m;
        arr[a] = INT_MIN;
        while (m--) {
            cin >> a;
            arr[a]++;
        }
    }
    
    int count = 0;
    for (int i = 0; i < 10005; i++) {
        if (arr[i] > 0)
            count++;
    }
    cout << count << "\n";
}

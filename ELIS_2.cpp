#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> LIS(n,1);
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin >> v[i];
    for (int i=1;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (v[i] > v[j] && LIS[i] < LIS[j] + 1)
                LIS[i] = LIS[j] + 1;
        }
    }
    cout << *max_element(LIS.begin(),LIS.end()) << endl;
}

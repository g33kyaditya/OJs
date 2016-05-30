#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
int main() {
    while (1) {
        long long int n;
        cin >> n;
        if (n == 0)
            return 0;

        vector<long long int> noOfStudents(n);
        vector<long long int> price(n);

        for (long long int i=0;i<n;i++)
            cin >> noOfStudents[i];

        for (long long int i=0;i<n;i++)
            cin >> price[i];

        sort(noOfStudents.begin(),noOfStudents.end());
        sort(price.begin(),price.end());
        long long int ans = 0;
        for (long long int i=0;i<n;i++) {
            ans = ans + price[i]*noOfStudents[n-1-i];
        
        }
        cout << ans << endl;
    }
}

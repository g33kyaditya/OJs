#include <iostream>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    int count = 0;
    while (n--) {
        int t;
        cin >> t;
        if (t%k ==0)
            count++;
    }
    cout << count << endl;
}

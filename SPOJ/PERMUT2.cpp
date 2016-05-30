#include <iostream>
using namespace std;
main()
{
    while (1) {
        int n;
        cin >> n;
        if (n == 0) 
            return 0;

        int arr[n];
        for (int i=0;i<n;i++)
            cin >> arr[i];

        bool status = true;

        for (int i=0;i<n;i++) {
            if (arr[arr[i]-1] != i+1) {
                status = false;
                break;
            }
        }

        if (status)
            cout << "ambiguous" << endl;
        else
            cout << "not ambiguous" << endl;
    }

        
}

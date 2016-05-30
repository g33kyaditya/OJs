#include <iostream>
#include <algorithm>
#include <vector>
//#include <iterator>
using namespace std;
main()
{
    int t;
    cin >> t;
    int foo = 0;
    while (t--) {
        foo++;
        long int total,number;
        cin >> total;
        cin >> number;
        int arr[number];
        int val;
        for (int i=0;i<number;i++) 
            cin >> arr[i];
        

        sort(arr,arr+number);
        long int sum = 0;
        int count = 0;
        
        for (int i=number-1;i>=0;i--) {
            sum = sum + arr[i];
            count++;
            if (sum >= total)
                break;
        }
        if (sum >= total) {
            cout << "Scenario #"<<foo<<":" << endl;
            cout << count << endl;
        
        }
        else {
            cout << "Scenario #"<<foo<<":" << endl;
            cout << "impossible" << endl;
    	}
    }
}

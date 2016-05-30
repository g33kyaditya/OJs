#include <iostream>
using namespace std;
main()
{
    unsigned long long int num;
    cin >> num;

    if (num%10 == 0) 
        cout << "2" << endl;
    else {
        cout << "1" << endl;
        cout << num%10 << endl;
    }
}

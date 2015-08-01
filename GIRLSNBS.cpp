#include <iostream>
#include <cmath>
using namespace std;
main()
{
    while (1) {
        float girls,boys;
        cin >> girls >> boys;
        
        if (girls == -1 && girls == boys)
            return 0;
        
        if (boys >= girls) {
            float max = boys;
            float min = girls;
            min++;
            cout << ceil(max/min) << endl;
        }
        else {
            float max = girls;
            float min = boys;
            min++;
            cout << ceil(max/min) << endl;
        }
    }
}


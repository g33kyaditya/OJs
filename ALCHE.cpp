#include <iostream>
using namespace std;
int main() {
    while (1) {
        double i,w;
        cin >> i >> w;

        if (i ==-1 && i==w)
            return 0;


        if (i/1000 == w/37)
            cout << "Y" << endl;
        else    
            cout << "N" << endl;
    }

} 

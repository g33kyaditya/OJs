#include <iostream>
#include <algorithm>
using namespace std;
main()
{
    int t;
    cin >> t;
    while (t--) {
        cout << endl;
        int ng,nm;
        cin >> ng >> nm;
        int godzilla[ng],mecha[nm];
        for (int i=0;i<ng;i++)
            cin >> godzilla[i];
        for (int i=0;i<nm;i++)
            cin >> mecha[i];
        sort (godzilla,godzilla+ng);
        sort (mecha,mecha+nm);
        int god = 0,mech = 0;
        while (god < ng && mech < nm) {
            if (godzilla[god] >= mecha[mech]) {
                mech++;
            }
            else    
                god++;
        }

        if (mech>= nm) 
            cout << "Godzilla" << endl;
        else
            cout << "MechaGodzilla" << endl;

    }
}

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
int main() {
    while (1) {
        int a,d;
        cin >> a >> d;
        if (a == d && a == 0)
            return 0;
        vector<int>attack(a),defend(d);
        for (int i=0;i<a;i++)
            cin >> attack[i];
        for (int i=0;i<d;i++)
            cin >> defend[i];
        sort (defend.begin(),defend.end());
        int last = defend[0];
        int secondLast = defend[1];
        bool ans = false;               // True - Offside    
                                        // False - Not Offside
        for (int i=0;i<a;i++) {
            if (attack[i] < secondLast) {
                ans = true;
                break;
            }
        }
        if (ans == true)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
}

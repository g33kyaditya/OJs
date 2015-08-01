#include <iostream> 
using namespace std;
int main() {
    
    int t1,t2,t3,a1,a2,a3;
    int count = 0;
    while (cin >> t1 >> t2 >> t3 >> a1 >> a2 >> a3) {
        count++;
        int solve = 0;
        if (t1 != 0)
            solve++;
        if (t2 != 0)
            solve++;
        if (t3 != 0)
            solve++;
        int penalty = 0;
        if (t1 != 0 )
            penalty += t1 + (a1-1)*1200;
       
        if (t2 != 0)
            penalty += t2 + (a2-1)*1200;
        
        if (t3 != 0 )
            penalty += t3 + (a3-1)*1200;
        

        cout << "team " << count << ": " << solve << ", " << penalty << endl;
    }
}

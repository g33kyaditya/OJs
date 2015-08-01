#include <iostream>
#include <cmath>
using namespace std;
void foo (int num) {
    if (num == 1)
        cout << "2(0)" ;
    else if (num == 2)
        cout << "2";
    else {
        int count = 0;
        int val = 1;
        while (val <= num) {
            val = val*2;
            count++;
        }
       int diff = num-val;
       cout << "2(" ; 
       foo(pow(2,count)) ; 
       cout << ")+"; 
       foo(diff);
    }
}
int main() {
    foo(137);
}

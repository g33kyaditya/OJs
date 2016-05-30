#include <iostream>
#include <cstdio>
using namespace std;
int main () {
    int t;
    string str;
    float n;
    int data = 0;
    cin >> t;
    while (t--) {
        data++;
        cin >> n >> str;
        if (str == "kg")
            printf ("%d %.4f lb\n",data,2.2046*n);
          //  cout << data << " " << 2.2046*n << " lb" << endl;
        else if (str == "lb")
            printf ("%d %.4f kg\n",data,0.4536*n);
            //cout << data << " " << 0.4536*n << " kg" << endl;
        else if (str == "l") 
            printf ("%d %.4f g\n",data,0.2642*n);
            //cout << data << " " << 0.2642*n << " g" << endl;
        else 
            printf ("%d %.4f l\n",data,3.7854*n);
            //cout << data << " " << 3.7854*n << " l" << endl;
    }
}

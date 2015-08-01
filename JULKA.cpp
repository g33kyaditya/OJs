#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
using namespace std;
char sum[105];

/*void shift (char *str,int length) {
    for (int i=length-1;i>=0;i--)
        str[i+1] = str[i];
    
    str[0] = '0';
}*/

void add (char *bigger,int lenBig,char *smaller,int lenSmall) {
    int temp = 0,i;
    for (i=0;i<lenBig;i++) {
        temp = bigger[i]-'0' + smaller[i]-'0' + temp;
        sum[i] = temp%10;
        temp = temp/10;
    }
    while (temp!=0) {
        sum[i++] = temp%10;
        temp = temp/10;
    }
}

main() {
    int t = 10;
    while (t--) {
        char X[105]="0",Y[105]="0";     //X = Klaudia, Y = Natalia
        cin >> X ;
        cin >> Y;
        
        int lenX = strlen(X);
        int lenY = strlen(Y);
        //Shift by one bit

       // shift(X,strlen(X));
       // shift(Y,strlen(Y));
        
       reverse (X,X+lenX);
       reverse (Y,Y+lenY);

    //    cout << X << endl << Y << endl;
        
        if (lenX >= lenY) {
            add (X,lenX,Y,lenY);
        }
        else {
            add (Y,lenY,X,lenX);
        }
       reverse (sum,sum+strlen(sum));       
       cout << sum << endl;

    }
}

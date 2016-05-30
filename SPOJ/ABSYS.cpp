#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
main()
{
    int t;
    cin >> t;
    while (t--) {
        cout << endl ;
        char str1[100],str2[100],str3[100];
        char plus,equal;
        cin >> str1 >> plus >> str2 >> equal >> str3;
        long int a = atoi(str1);
        long int b = atoi(str2);
        long int c = atoi(str3);
        long int flag = 0;
        for (int i=0;i<strlen(str1);i++) {
            if (str1[i] == 'm') {
                flag = 1;
                break;
            }
        }

        for (int i=0;i<strlen(str2);i++) {
            if (str2[i] == 'm') {
                flag = 2;
                break;
            }
        }

        for (int i=0;i<strlen(str3);i++) {
            if (str3[i] == 'm') {
                flag = 3;
                break;
            }
        }

        if (flag == 1) 
            cout << c-b << " + " << b << " = " << c << endl;
        
        else if (flag == 2) 
            cout << a << " + " << c-a << " = " << c << endl;
       
        else 
            cout << a << " + " << b << " = " << a+b << endl;
    }
}


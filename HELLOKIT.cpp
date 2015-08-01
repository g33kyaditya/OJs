#include <iostream>
#include <string>
using namespace std;
int main () {
    int num;
    string str;
    while (1) {
        cin >> str;
        if (str == ".")
            return 0;
        cin >> num;
        int foo;
        foo = num;
        int length = str.length();
        while (num--)
            str+=str;
        str+=str;
        
        int j=0;
        for (int i=0;i<length;i++) {
            for (int j=i;j<(foo*length)+i;j++)
                cout << str[j];
            cout << endl;
        }
       
    }
}   

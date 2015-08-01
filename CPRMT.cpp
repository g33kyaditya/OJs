#include <iostream>
using namespace std;
int main() {
    char str1[1005],str2[1005];
    while (cin >> str1 >> str2) {
        int f1[130]={0},f2[130]={0};
    //    for (int i=0;i<130;i++) {
    //        f1[i] = 0;
    //        f2[i] = 0;
    //    }
        
        for (int i=0;str1[i]!='\0';i++)
            f1[str1[i]]++;
        for (int i=0;str2[i]!='\0';i++)  
            f2[str2[i]]++;

        for (int i=90;i<130;i++) {
            while (f1[i]-- && f2[i]--)
            	cout << char(i);
        }
        cout << endl;
    }
}

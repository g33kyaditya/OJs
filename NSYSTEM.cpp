#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1,str2;
        cin >> str1 >> str2;
        int a=1,d1=0;
        for (int i=0;i<str1.length();i++) {
            if ('0' <= str1[i] && str1[i] <= '9'){
                a = str1[i]-'0';
            }
            else {
                if (str1[i] == 'm') {
                    d1 = d1 + a*1000;
                    a = 1;
                }
                else if (str1[i] == 'c') {
                    d1 = d1 + a*100;
                    a = 1;
                }
                else if (str1[i] == 'x') {
                    d1 = d1 + a*10;
                    a = 1;
                }
                else {
                    d1 = d1 + a*1;
                    a = 1;
                }
            }
        }
         int d2 = 0;
	 a = 1;
         for (int i=0;i<str2.length();i++) {
            if ('0' <= str2[i] && str2[i] <= '9'){
                a = str2[i]-'0';
            }
            else {
                if (str2[i] == 'm') {
                    d2 = d2 + a*1000;
                    a = 1;
                }
                else if (str2[i] == 'c') {
                    d2 = d2 + a*100;
                    a = 1;
                }
                else if (str2[i] == 'x') {
                    d2 = d2 + a*10;
                    a = 1;
                }
                else {
                    d2 = d2 + a*1;
                    a = 1;
                }
            }
        }
        
        int d = d1 + d2;
	int t;
	t = d;
	int p = t%1000;
	if (p!=t) {
	  p = t/1000;
	  if (p!=1)
        cout << p << "m"; 
	  else
        cout << "m";
      t = t%1000;
	 } 
	
	p = t%100;
	if (p!=t) {
	  p = t/100;
	  if (p!=1)
        cout << p << "c";
	  else
        cout << "c";
      t = t%100;
	}
	
	p = t%10;
	if (p!=t) {
	  p = t/10;
	  if (p!=1)
        cout << p << "x";
	  else
        cout << "x";
      t = t%10;
	}
	
	p = t%1;
	if (p!=t) {
	  p = t/1;
	  if (p!=1)
        cout << p << "i";
	  else
        cout << "i";
      t = t%1;
	}
	
	cout << endl;
    
      
    }
}

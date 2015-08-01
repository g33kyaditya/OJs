#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

string subtractBigInteger (string str1,string str2) {
	string str3 ;
	reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
	int i,borrow=0,temp;
	
	for (i=0;i<str1.length();i++) {
		if ((i+1) > str2.length())
            str2.push_back('0');
        
        temp = str1[i]-'0'-(str2[i]-'0') -borrow;
        if (temp < 0) {
            temp = temp + 10;
            borrow = 1;
        }
        str3.push_back(temp + '0');
	}	
	reverse (str3.begin(),str3.end());
    return str3;
}
string multiplyBigInteger(string str) {
	int temp = 0,carry = 0;
	string str3;
	reverse (str.begin(),str.end());
	for (int i=0;i<str.length();i++) {
		temp = (str[i]-'0')*2;
		str3.push_back(temp%10 + carry + '0');
		carry = temp/10;
	}
	while (carry!= 0) {
		str3.push_back(carry + '0');
		carry = carry/10;
	}
	reverse (str3.begin(),str3.end());
	return str3;
}
int main()
{
    string n,str3;
    string str2="1";
    while(cin >> n) {        
        
        if (n == "1")
            cout << "1" << endl;
        else {
    		//n-1
    		str3 = subtractBigInteger(n,str2);
        	//Multiply 2*(n-1) = 2*(str3)
        	str3 = multiplyBigInteger(str3);
        	cout << str3 << endl;
        }
    }
}

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
long long int solve (string str) {
    long long int val = 0;
    for (int i=0;i<str.length();i++)
	val = val*10 + (str[i]-'0');

    return val;
}
int main() {
    int t;
    cin >> t;
    
    
    while (t--) {
        long long int val,ans=0;
	int count = 0;
	cout << endl;
        string str;
        vector <char> v1;
	vector <long long int> v2;
	while (1) {
            cin >> str ;
            if (str == "=")
                break;
            
            else if (str!="+" && str!= "-" && str!= "*" && str!= "/" && str!= " ") {
		count++;
		val = solve (str);
		//cout << "Val = " << val << endl;
		v2.push_back(val);
		if (count == 1)
		    ans = val;
	    }
	    else if (str == "+") 
		v1.push_back('+');
	    else if (str == "-")
		v1.push_back('-');
	    else if (str == "*")
		v1.push_back('*');
	    else if (str == "/")
		v1.push_back('/');
        }
        //copy(v1.begin(),v1.end(),ostream_iterator<char> (cout,"   "));
        //cout << endl;
	//copy(v2.begin(),v2.end(),ostream_iterator<long long int> (cout,"   "));
	vector<char>::iterator it = v1.begin();
	int i = 1;
	while (it != v1.end()) {
	    if (*it == '+')
		ans = ans + v2[i];
	    else if (*it == '-')
		ans = ans - v2[i];
	    else if (*it == '*')
		ans = ans*v2[i];
	    else
		ans = ans/v2[i];
	    
	    i++;
	    it++;
	}
	cout << ans << endl;
        
    }        
}

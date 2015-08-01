#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;
int main() {
    string str;
    while (cin >> str) {
        bool upper = false,underScore=false,flag = false;
        for (int i=0;i<str.length();i++) {
            if (isupper(str[i]))
                upper = true;
            if (str[i] == '_') {
                underScore = true;
                if (str[i+1] == '_')
                    flag = true;
            }
        }
        if (flag == true) {
           cout << "Error!" << endl;
           continue;
        }
		if (isupper(str[0]) || str[0] == '_' || str[str.length()-1] == '_') {
			cout << "Error!" << endl;
			continue;
		}
        if (upper && underScore)  {
            cout << "Error!" << endl;
        	continue;
        }
                   
            if (upper) {
                for (int i=0;i<str.length();i++) {
                    if (('a'<=str[i] && str[i]<='z') || ('A'<= str[i] && str[i]<= 'Z')) {
                    	if (isupper(str[i])) {
                    	    cout << "_"<<char(tolower(str[i]));
                    	}
                    	else
                        	cout << str[i];
                	}
                	else {
                		cout <<"Error!" ;
                		break;
                	}
            }
        		cout << endl;
            }
            else {
                for (int i=0;i<str.length();i++) {
                    if (str[i] == '_' && str[i+1] == '_') {
                    	cout << "Error!" ;
                    	break;
                    }
                    if (('a'<=str[i] && str[i]<='z') || str[i] == '_') { 
                    	if (str[i] == '_') {
                        	cout << char(toupper(str[i+1]));
                        	i++;
                    	}
                    else
                        cout << str[i];
                	}
                	else {
                		cout << "Error!";
                		break;
                	}
                
            	}
            	cout << endl;
            }
        }
    
}

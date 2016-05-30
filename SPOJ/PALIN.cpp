#include <string>
#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
string arr;
string original;
inline void foo (long long int x ) {
    
    if (x%2 !=0) {
        if (arr[x/2] != '9') {
            arr[x/2]++;
        }
        else {
            arr[x/2] = '0';
            int k = x/2 -1;
            while (k >=0) {
                if (arr[k] == '9')
                    arr[k] = '0';
                else {
                    arr[k]++;
                    break;
                }
                k--;
            }
        
        k = x/2 + 1;
        while (k < x) {
            if (arr[k] == '9')
                arr[k] = '0';
            else {
                arr[k]++;
                break;
            }
            k++;
        }
    } 
}
    
    else {
        if (arr[x/2] != '9') {
            arr[x/2]++;
            arr[x/2 - 1]++;
        }
        else {
        	arr[x/2] = '0';
        	arr[x/2 -1] = '0';
        	int k = x/2 + 1;
        	while (k < x) {
        		if (arr[k] == '9')
        			arr[k] = '0';
        		else {
        			arr[k]++;
        			break;
        		}
        		k++;
        	}
        	
        	k = x/2-2;
        	while (k >= 0) {
        		if (arr[k] == '9')
        			arr[k] = '0';
        		else {
        			arr[k]++;
        			break;
        		}
        		k--;
        	}
        	
        }
    }
}
main()
{
    long long int t,num;
    cin >> t;
    while (t--) {
        cin >> arr;
        original = arr;
        int x = arr.length();
        //Mirroring
            for (int i=0;i<x/2;i++) {
                arr[x-i-1] = arr[i];
            }
        //cout << arr << endl;
        //Check mirrored string to be larger
        int flag = FALSE;
        if (arr <= original)
            flag = TRUE;
     	
        if (flag == TRUE)   
     		foo(x);
		
	/*	flag = TRUE;
		for (int i=0;i<x;i++) {
			if (arr[i] != original[i]) {
				flag = FALSE;
				break;
			}
		}
		
		if (flag == TRUE)
			foo(x);  */    		
     	
     	
     	if (arr[0] == '0') {
     			cout << "1";
     			for (int i=0;i<x-1;i++)
     				cout << "0";
     			cout << "1";
     			cout << endl;
     		}
     	else {
     		cout << arr ;
     		cout << endl;
     	}
    }
}


#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    float val;
    string str;
    int i2=0,i5=0,i7=0;
    for (int i=0;i<n;i++) {
        cin >> str;
        if (str[0] == '1' && str[2]== '2')
            i5++ ;
        else if (str[0] == '3')
            i7++ ;
        else
            i2++ ;
    }
    
    //Pairing 3/4 and 1/4

    int count = 0;
    while (i7>=0 && i2>=0) {
        if (i7-1 >=0 && i2-1 >=0) {
            count++;
            --i7;
            --i2;
        }
        else
            break;
    }
    while (--i7>=0)
        count++;
    
    //Pairing 1/2
    
    if (i5%2 !=0) {
        int temp;
        temp = i5-((i5/2)*2);
        temp = i5-temp;
        temp=temp/2;
        count = count+temp;
        i5 = i5-((i5/2)*2);
        while (i5>=0) {
            if (i2-2 >= 0 && i5-1 >=0) {
                count++;
                i2 = i2-2;
                i5--;
            }
            else if (i2-1 >= 0 && i5-1 >=0) {
                count++;
                i2 = i2-1;
                i5--;
            }
            else
                break;
        }
    }
    else {
        count = count + i5/2;
        i5=0;
    }

    while (--i5 >=0)
        count++;

    //Pairing 1/4
    while (i2 >=0) {
        if (i2-4 >=0) {
            count++;
            i2 = i2-4;
        }
        else if (i2-3 >=0) {
            count++;
            i2 = i2-3;
        }
		else if (i2-2 >=0) {
            count++;
            i2 = i2-2;
        }
        else if (i2-1 >=0) {
            count++;
            i2 = i2-1;
        }        
        else
            break;
    }

    while (--i2>=0) 
        count++;

   cout << count+1 << endl;

}

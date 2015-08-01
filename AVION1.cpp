#include <iostream>
#include <string>
using namespace std;
int main() {
    int n = 5;
    bool arr[6] = {false} ;
    string str;
    int row = 0;
    while (n--) {
        row++;
        cin >> str;
        for (int i=0;i<str.length()-2;i++) {
            if (str[i] == 'F' && str[i+1] == 'B' && str[i+2] == 'I') {
                arr[row] = true; 
                break;
            }
        }
    }
        bool foo = false;
        for (int i=0;i<6;i++) {
            if (arr[i] == true) {
                foo = true;
                cout << i << endl;
            }
        }
        
        if (!foo) 
            cout << "HE GOT AWAY!" << endl;
    
}

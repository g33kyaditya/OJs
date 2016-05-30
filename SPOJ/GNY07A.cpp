#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dataSetCount=0;
    while (n--) {
        int t;
        string str;
        cin >> t >> str;
        dataSetCount++;
        cout << dataSetCount << " ";
        for (int i=0;i<str.length();i++) {
            if ((i+1) != t)
                cout << str[i];
        }
        cout << endl;
    }
}

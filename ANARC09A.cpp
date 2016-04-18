#include <iostream>
using namespace std;
int main() {
    string str;
    long long int count = 0;
    while(1) {
        cin >> str;
        count++;
        if (str[0] == '-')
            break;
        
        int open = 0, cost = 0;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '{')
                open++;
            else if (str[i] == '}') {
                if (open > 0)
                    open--;
                else {
                    open++;
                    cost++;
                }
            }
        }

        cout << count << ". " << cost + open/2 << "\n";
    }
}

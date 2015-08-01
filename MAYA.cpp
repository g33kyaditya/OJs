#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            return 0;
        
        cin.clear();
        cin.ignore();
        string str;
        int temp = n;
        int dig[n];
        int j = 0;
        while (n--) {
            getline(cin,str);
            int countOfDots = 0,countOfZeroes = 0,countOfDashes = 0;
            for (int i=0;i < str.length();i++) {
                if (str[i] == '.')
                    countOfDots++;
                else if (str[i] == '-')
                    countOfDashes++;
            }
            dig[j++] = countOfDashes*5 + countOfDots  ; 
        }
        long long int ans = 0;
        bool flag = false;
        for (int i=j-1;i>=0;i--) {
            if (i == j-1 || i == j-2) {
                ans = ans + dig[i]*pow(20,(j-1-i));
            }
            else if (i == j-3) {
                ans = ans + dig[i]*360;
                flag = true;
            }
            else {
  
                    ans = ans + 360*dig[i]*pow(20,j-3-i);
  
            }
        }
        cout << ans << endl;
        cout << endl;
    }
} 

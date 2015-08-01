#include <iostream>
using namespace std;
int main () {
    string str;
    while (1) {
        cin >> str;
        if (str == "0")
            return 0;
        
        int n = str.length();
        if (n < 2) {
            cout << "1" << endl;
            continue;
        }
        unsigned long long int dp[n+5]={0};
        int x,ans;
        dp[0]=1;
        for (int i=1;i<str.length();i++) {
            x = (str[i-1]-'0')*10 + (str[i]-'0');
            if (str[i]-'0')
                dp[i] = dp[i-1];
            if (x>=10 && x<=26) {
                int k = i-2;
                if (k >= 0) 
                    dp[i] = dp[i] + dp[i-2];
                else
                    dp[i] = dp[i] + dp[0];
            }
        }
        cout << dp[n-1] << endl;
    }
}

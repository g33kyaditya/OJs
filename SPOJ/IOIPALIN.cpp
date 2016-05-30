#include <iostream>
#include <string>
using namespace std;
string str1,str2;
int solve (int i,int j,string) {
    if (str1[i]==str1[j] || str2[i]==str2[j])
        return 0;
    int count1=0,count2=0;
    str1.insert(i+1,str1[j]);
    count1++;
    solve()
    
}
int main() {
    int n;
    while (cin >> n) {
        cin >> str1;
        str2 = str1;
        if (n%2 == 0)
            solve ((n/2)-1,n/2);
        else
            solve ((n/2)-1,(n/2)+1);
    }
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
    int t;
    cin >> t;
    cin.clear();
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        cin.clear();
        cin.ignore();
        
        for (int i=0;i<n;i++)
            getline(cin,v[i]);
        
        cout << endl;
        sort (v.begin(),v.end());
        int temp=0;
        for (int i=0;i<n;i++) {
            int count = 0;
            for (int j=i;j<n;j++) {
                if (v[i] == v[j])
                    count++;
                else {
                     break;
                }    
            }
            
            if (i== 0)
                cout << v[i] << " " << count << endl;
            else if (v[i] != v[i-1]) 
                cout << v[i] << " " << count << endl;
        }
   
    }
}

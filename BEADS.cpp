#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator> 
#include <utility>
using namespace std;
//bool compareFunction (vector<pair<string,int> > &v1,vector<pair<string,int> > &v2) {
   // return (v1.first < v2.first);
//}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int l = str.length();
        str = str+str;
        vector<pair<string,int> > v;
        pair<string,int> t;
        for (int i=0;i<l;i++) {
            t.first = str.substr(i,l);
            t.second = i;
            v.push_back(t);
        }
        sort(v.begin(),v.end());
        cout << v[0].second + 1<< endl;

    }
}

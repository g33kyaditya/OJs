#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        if (n == 0)
            return 0;
        stack<int> s;
        vector<int> v(n);
        vector<int> dest;
        for (int i=0;i<n;i++)
            cin >> v[i];

        int val = 1;
        bool answer = true;
        for (int i=0;i<n;i++) {
            if (val == v[i]) {
                dest.push_back(val);
                val++;
            }
            else {
                if (!s.empty()) {
                    while (!s.empty() && val == s.top() ) {
                        s.pop();
                        dest.push_back(val);
                        val++;
                    }
                    if (!s.empty()) {
                        if (v[i] < s.top()) 
                            s.push(v[i]);
                        else {
                            answer = false;
                            break;
                        }
                    }
                    else
			            s.push(v[i]);
                }
                else 
                    s.push(v[i]);
                
            }
        }

        if (answer == false) {
            cout << "no" << endl;
            continue;
        }

        while (!s.empty()) {
            int t = s.top();
            s.pop();
            dest.push_back(t);
        }
        sort (v.begin(),v.end());
        for (int i=0;i<n;i++) {
            if (v[i]!=dest[i]) {
                answer = false;
                break;
            }
        }

        if (answer)
            cout << "yes" << endl;
        else
            cout << "no" << endl;


    }
}

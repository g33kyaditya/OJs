#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    if (n == 0) {
    	cout << "0" << endl;
		return 0;
	}
    vector <int> v;
    long long int temp,rem,t=0;
    while (n != 0) {
        if (n < 0) {
            temp = -n;
            temp = temp/2;
            if ((temp*2 +n) < 0) {
                rem = (temp+1)*2 + n;
                n = temp+1;
            }
            else {
                rem = temp*2 + n;
                n = temp;
            }
            v.push_back(rem);
            t++;
        }
        else {
            temp = n;
            temp = temp/2;
            rem = n - temp*2;
            v.push_back(rem);
            n = -temp;
            t++;
        }
    }
    while (--t >= 0)
        cout << v[t];
    cout << endl;
}

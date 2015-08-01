#include <iostream>
#include <cmath>
using namespace std;
main()
{
    unsigned long long int n;
    cin >> n;
    if (n == 0 || n == 1)
		cout << "TAK" << endl;
	else {
		bool flag = false;
		for (unsigned long long int i = 2;i<=n;i=i*2) {
			if (i == n) {
				flag = true;
				break;
			}
		}
		
		if (flag)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}
}

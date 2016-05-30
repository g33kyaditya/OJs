#include <iostream>
using namespace std;
main()
{
	int num;
	while(1) {
		cin>>num;
		if(num ==42)
			return 0;
		else
			cout<<num<<"\n";
	}
	return 0;
}

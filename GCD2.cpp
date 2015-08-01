#include <cstdio>
#include <cmath>
#include <cstring>
//double fmod (double numer,double denom);
int gcd (int a,int b) {
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
main()
{
	int t;
	int A;
    char B[255];
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&A);
		scanf("%s",B);
		int val=0;
        
        if (A == 0) {
        	printf("%s\n",B);
        	continue;
        }
       
        for (int i=0;i<strlen(B);i++) {
            	val = (val*10 + B[i]-'0')%A;
        }
		val = gcd(A,val);
        printf("%d\n",val);
	}
	return 0;
}

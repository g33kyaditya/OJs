#include <cstdio>
main()
{
	int t;
	int a;
	long long int b;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&a);
		scanf("%lld",&b);
		int rem=b%4;
		int dig;
		if (b==0 && a!=0) {
			printf("1\n");
			continue;	
		}
		if (rem==0) 
			dig=(a*a*a*a)%10;
		
		else if (rem==1) 
			dig=(a)%10;

		else if (rem==2)
			dig = (a*a)%10;

		else if (rem==3)
			dig=(a*a*a)%10;

		printf("%d\n",dig);
	}
}

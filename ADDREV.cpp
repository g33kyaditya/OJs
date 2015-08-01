#include <stdio.h>
#define TRUE 1
#define FALSE 0
inline int rev(int num) {
	int rem=0,s=0;
	int check=FALSE;
	while(num!=0) {
		rem=num%10;
		if (rem!=0)
			check=TRUE;
		if (check==TRUE) {
			s=rem+s*10;
		}
		num=num/10;
	}
	return s;
}
main()
{
	int a,b,t;
	scanf("%d",&t);
	while (t--) {
		int sum=0;
		scanf("%d%d",&a,&b);
		sum=rev(a)+rev(b);
		sum=rev(sum);
		printf("%d\n",sum);
	}
	return 0;
}

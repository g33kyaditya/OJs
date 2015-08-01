#include <stdio.h>
main()
{
	int x,y,t;
	int val;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&x);
		scanf("%d",&y);

		if (y>x || (x-y)%2 !=0) {
			printf("No Number\n");

			}
		else if (y<=x) {
			if (x-y ==2 || x-y==0) {
			if (y%2==0 && x%2==0)
				val=x+y;
			else if (y%2!=0 && x%2!=0)
				val=x+y-1;
			
			printf("%d\n",val);
			}
			else
			printf("No Number\n");
		}
	
	}
	return 0;
}	

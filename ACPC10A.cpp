#include <cstdio>
main()
{
	int a,b,c;
	for (int i=1;i>0;i++) {
		scanf("%d%d%d",&a,&b,&c);
		
		if ((a==b)&&(b==c)&&(a==0)) 	
			return 0;

		if (b-a == c-b) {
			printf("AP %d\n",c+(b-a));
		}
		else {
			printf("GP %d\n",c*(b/a));
		}
	
	}
	return 0;
}

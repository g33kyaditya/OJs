#include <cstdio>
main()
{
	int n;
	while (1) {
		scanf("%d",&n);
		if (n==0)
			return 0;
		int val = (n*(n+1)*((2*n)+1))/6;
		printf("%d\n",val);
	}
	return 0;
}

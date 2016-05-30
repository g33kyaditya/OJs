#include <cstdio>
main()
{
	long long int t;
	scanf("%lld",&t);
	while (t--) {
		printf("\n");
		long long int n;
		scanf("%lld",&n);
/*		if (n==0) {
			printf("NO\n");
			continue;
		} */
		long long int sum=0,t;
		for (long long int i=0;i<n;i++) {
			scanf("%lld",&t);
			sum=(sum+t)%n;
		}
/*		for (int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
			sum=sum+arr[i];
		} */

		if (sum)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

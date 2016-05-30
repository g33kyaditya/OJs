#include <cstdio>
main()
{
	int n;
	for (int i=1;i>0;i++) {
		scanf("%d",&n);
		if (n==-1)
			return 0;
		
		int *arr=new int[n];
		int sum=0;
		for (int j=0;j<n;j++) {
			scanf("%d",&arr[j]);
			sum=sum+arr[j];
		}
		
		int avg=sum/n;
		if (sum%n !=0) {
			printf("-1\n");
			continue;
		}
		
		int diff=0;

		for (int j=0;j<n;j++) {
			
			if (arr[j]>avg) 
				diff=diff + (arr[j]-avg);
		}

		printf("%d\n",diff);
			

	}
	return 0;
}

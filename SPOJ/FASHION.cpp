#include <cstdio>
inline void sort (int *man,int *woman,int size) {
	for (int i=0;i<size;i++) {
		for (int j=0;j<size-1;j++) {
			if (man[j]>man[j+1]) 
				man[j]=man[j]+man[j+1]-(man[j+1]=man[j]);

			if (woman[j]>woman[j+1])
				woman[j]=woman[j]+woman[j+1]-(woman[j+1]=woman[j]);
				
		}
	}
}

inline int sum (int *man,int *woman,int size) {
	int val=0;
	for (int i=0;i<size;i++) 
		val=val+man[i]*woman[i];

	return val;
}
main()
{
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		int man[n],woman[n];

		for (int i=0;i<n;i++)
			scanf("%d",&man[i]);

		for (int i=0;i<n;i++) 
			scanf("%d",&woman[i]);

		sort (man,woman,n);

		int val=sum(man,woman,n);

		printf("%d\n",val);


	}
}

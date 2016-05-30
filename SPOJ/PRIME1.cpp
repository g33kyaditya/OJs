#include <cstdio>
#include <iostream>
using namespace std;
#include <cmath>
#define TRUE 1
#define FALSE 0
#define MAXDIFF 100000
int tempArr[MAXDIFF];			//To store temporary Prime indexes for myPrime
int myPrime[MAXDIFF];		//To store prime values. myPrime[0]={some value},myPrime[1]={some value}...
int arr[MAXDIFF];
int t;
int m,n;
inline int fillMyPrime (int n) {
	for (int i=2;i<MAXDIFF;i++) {
		tempArr[i]=TRUE;
		myPrime[i]=FALSE;	
	}

	int myPrimeRange=floor(sqrt((double)n));
	
	int z = floor(sqrt((double)myPrimeRange));
	for (int i=2;i<=z;i++) {
		if (tempArr[i]) {
			for (int j=i*i;j<=myPrimeRange;j=j+i)
				tempArr[j]=FALSE;
		}
	}
	
	t=0;
	for (int i=2;i<=myPrimeRange;i++) {
		if (tempArr[i]) {
		//	cout <<"\n"<<i;
			myPrime[t++]=i;
		//	cout <<"\nmyPrime["<<z<<"] = "<<myPrime[z];

		}

	}
} 
inline void sieve () {
	int value,d;
	for (int i=0;i<t;i++) {
		value=myPrime[i];
		d=m/value;
		d=d*value;
		
		for (int j=d;j<=n;j=j+value) {
			if (j<m)
				continue;
			
			arr[j-m]=FALSE;
		}
	}
	
	for (int i=0;i<t;i++) {
		if (myPrime[i]>=m && myPrime[i]<=n)
			printf("%d\n",myPrime[i]);
	}
	
	for (int i=0;i<n-m+1;i++) {
		if (arr[i] && i+m!=1) 
			printf("%d\n",i+m);
		
	}
}
main()
{
	int t;

	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&m,&n);
	//	int size = n-m+1;
		fillMyPrime(n);
		
		for (int i=0;i<MAXDIFF;i++ )
			arr[i]=TRUE;
		
		sieve ();
		printf("\n"); 
	}



	return 0;
}

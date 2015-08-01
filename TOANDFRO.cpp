#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
main()
{
	int n;
	while (1) {
		scanf("%d",&n);
		if (n==0)
			return 0;
        
        char str[500];
        cin >> str;
        int row  = strlen(str)/n;
        //cout << row << "    " << n << endl;
        char arr[row][n];
        int k=0;
        for (int i=0;i<row;i++) {
            if (i%2 !=0) {
                for (int j = n-1;j>=0;j--)
                    arr[i][j] = str[k++];
            }
            else {
                for (int j=0;j<n;j++)
                    arr[i][j] = str[k++];
            }
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<row;j++)
                printf("%c",arr[j][i]);
        }

        cout << "\n";


    }
}


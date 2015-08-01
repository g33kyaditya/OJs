#include <cstdio>
main()
{
    int t,n;
    int arrive[1000],depart[1000],count[1000];
    scanf("%d",&t);
    while (t--) {
            for (int i=0;i<=1000;i++)
                count[i]=0;
            
            scanf("%d",&n);
            for (int i=0;i<n;i++)
                scanf("%d",&arrive[i]);

            for (int i=0;i<n;i++)
                scanf("%d",&depart[i]);

            for (int i=0;i<n;i++) {
                    for (int k=arrive[i];k<depart[i];k++)
                            count[k]++;
                }

            int max=count[1];

            for (int k=1;k<=1000;k++) {
                    if (count[k]>max)
                        max=count[k];
                }

                printf("%d\n",max);
        
        }

    }

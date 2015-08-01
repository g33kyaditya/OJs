#include <cstdio>
main()
{
   float c;
   float sum;
   while (1) {
        scanf("%f",&c);
        if (c == 0.00)
            return 0;
        long long int count=0;
        float sum=0;
        for (long long int i=2;;i++) {
            sum = sum + 1.0/i;
            count++;
            if (sum>=c)
                break;
        }

        printf("%lld card(s)\n",count);
    
    }
}

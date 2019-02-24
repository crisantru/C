#include<stdio.h>

main()
{
    int count = 1;

    printf("N\t110*N\t100*N\t1000*N\n");

    while(count <= 10)
    {
        printf("\n%d\t%d\t%d\t%d", count, 10 * count, 100 * count, 1000 * count);
        count++;
    }

    return 0;

}

#include<stdio.h>

main()
{
    int x = 1, total, y;

    while(x <= 10)
    {
        y = x*x;
        printf("%d\n", y);
        total += y;

    }

    printf("Total es: %d\n", total);

    return 0;


}

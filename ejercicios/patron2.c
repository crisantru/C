#include<stdio.h>

main()
{
    int i, j;

    for(i = 10; i >= 1; i--)
    {
    //printf("i: %d", i);
        for(j = 1; j <= i; j++)
        {
      //      printf("j: %d", j);
            printf("*");

        }
    printf("\n");


    }

    return 0;

}

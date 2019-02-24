#include<stdio.h>

main()
{
    int i, j, k;

    for(i = 10; i >= 1; i--)
    {

        for(j = 1; j <= 10  ; j++)
        {


            for(k = 0; k <= 10; k++)
            {

                printf("*");

            }

            printf("\n");

        }

        printf("\n");
    }

    return 0;

}

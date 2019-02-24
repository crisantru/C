#include<stdio.h>

main()
{
    int x, i, j;



    for(i = 1; i <= 5; i++)
    {
        printf("\nDame un numero entre el rango de 1-30: ");
        scanf("%d", &x);

        if(x > 30)
        {
            printf("\nTu numero rebasa el rango....");
            break;

        }

        printf("\nnumero %d: %d\n\n", i, x);

        for(j = 1; j <= x; j++)
        {

            printf("*");

        }

    }

    return 0;

}

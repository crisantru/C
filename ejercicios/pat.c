#include<stdio.h>

main()
{
    int i, j, x, y;

    printf("Dame dos numeros entre el rango del 1-20: ");
    scanf("%d%d", &x, &y);

    for(i = 1; i <= y; i++)
    {
        for(j = 1; j <= x; j++)
        {
            printf("@");

        }
    printf("\n");

    }

    return 0;

}

#include<stdio.h>
#include<stdlib.h>

main()
{
    int i = 1;

     for(i = 1; i <= 20; i++)
    {
        printf("%10d", 1 + (rand() % 6));

        if(i % 5 == 0)          //le da formato a la impresion para que no se desconfigure
            printf("\n");

    }


    return 0;

}

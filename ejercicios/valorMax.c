#include<stdio.h>

main()
{

    int number, count = 1, max = 0;

    while(count <= 10)
    {
        printf("Inserta el numero %d : ", count);
        scanf("%d", &number);

        if(number > max)
            max = number;

        count++;

    }

    printf("el numero mayor de los 10 es: %d", max);

    return 0;

}

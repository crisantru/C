#include<stdio.h>

main()
{
    int i, suma = 0;

    for(i = 1; i <=99; i++)
    {
        if((i % 2) != 0 )
        {
            //printf("\n%d: impar", i);
            suma += i;
        }

        i++;
    }

    printf("\nLa suma de todos los numeros impares es: %d", suma);

    return 0;

}

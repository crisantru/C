#include<stdio.h>

main()
{
    int i, n, suma = 1;

    printf("Dame el numero de factorial a calcular: ");
    scanf("%d", &n);

    for(i = n; i >= 1; i--)
        suma *= i;

    printf("\nEl factorial es: %d", suma);

    return 0;

}

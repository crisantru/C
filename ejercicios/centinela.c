#include<stdio.h>

main()
{
    int numero , suma = 0;

    while(numero != -1)
    {
        suma += numero;     //se guarda primero para que no afecte el -1 en la suma y le reste el valor...
        printf("Para terminar teclea -1. Dame un numero: ");
        scanf("%d", &numero);

    }

    printf("La suma es: %d", suma);

    return 0;
}

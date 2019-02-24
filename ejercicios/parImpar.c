#include<stdio.h>

main()
{
    int numero;

    printf("Escribe un numero: ");
    scanf("%d", &numero);

    if(numero%numero == 1 || numero%2 == 0)
        printf("Tu numero es par");
    else
        printf("Tu numero es impar");

    return 0;


}

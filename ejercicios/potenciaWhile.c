#include<stdio.h>

main()
{
    int numero, potencia, i = 1, res = 0;

    printf("Dame el numero a calcular su potencia: ");
    scanf("%d", &numero);
    printf("Escribe la potencia a calcular: ");
    scanf("%d", &potencia);

    while(i <= potencia)
    {
        res += numero * numero;
        printf("\nPotencia %d:  %d", i, res);
        i++;

    }

    return 0;


}

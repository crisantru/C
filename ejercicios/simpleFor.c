#include<stdio.h>

main()
{
    int numeroCuenta, i;
    float limiteCredito, deuda, nuevoCredito = 0;

    for(i = 1; i <= 3; i++)
    {
        printf("\n\nDame el numero de cuenta del cliente %d: ", i);
        scanf("%d", &numeroCuenta);
        printf("\nEscribe el limite de credito establecido: ");
        scanf("%f", &limiteCredito);
        printf("\nSaldo actual (deuda a la empresa): ");
        scanf("%f", &deuda);

        nuevoCredito = limiteCredito / 2;

        if(deuda > nuevoCredito)
        {
            printf("\nCuenta Cliente: %d", numeroCuenta);
            printf("\nNuevo Credito: %.2f", nuevoCredito);
            printf("\nEste Cliente Excedio su credito....");

        }

    }

    return 0;

}

#include<stdio.h>

main()
{
    int numCuenta;
    float saldoCredito, cargoMes, creditoMes, limiteCredito, resultado = 0;

    printf("\n\nDame el numero de cuenta del cliente (-1 para terminar): ");
    scanf("%d", &numCuenta);

    while(numCuenta != -1)
    {
        printf("\nDame el saldo actual del credito del cliente: ");
        scanf("%f", &saldoCredito);
        printf("\nintroduce los cargos de credito del mes: ");
        scanf("%f", &cargoMes);
        printf("\nDigita el cedito autorizado para este mes: ");
        scanf("%f", &creditoMes);
        printf("\nIntroduce cual es el limite del credito del cliente: ");
        scanf("%f", &limiteCredito);
        resultado = (saldoCredito + cargoMes) - creditoMes ;

        if(resultado > limiteCredito)
        {
            printf("\nCuenta: %d", numCuenta);
            printf("\nLimite de Credito: %.2f", limiteCredito);
            printf("\nBalance del mes (credito solicitado): %.2f", saldoCredito + cargoMes);
            printf("\nLo sentimos ya no se puede realizar otro movimiento CREDITO EXCEDIDO");
        }

        if(resultado <= limiteCredito)
        {
            printf("\nMOVIMIENTO: CREDITO AUTORIZADO");
        }


        printf("\n\nDame el numero de cuenta del cliente (-1 para terminar): ");
        scanf("%d", &numCuenta);

    }

    return 0;

}

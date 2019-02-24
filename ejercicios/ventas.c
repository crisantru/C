#include<stdio.h>

main()
{
    float ventas, comision = 0;

    printf("\nDame las ventas que genraste (-1 para terminar): ");
    scanf("%f", &ventas);

    while(ventas != -1)
    {
        comision = ventas * 0.09;
        printf("\ncomision: %.2f", comision);
        comision += 200;
        printf("\ncomision: %.2f", comision);
        printf("\ntu sueldo a la semana es de: %.2f", comision);
        printf("\nDame las ventas que genraste (-1 para terminar): ");
        scanf("%f", &ventas);
    }

    return 0;
}

#include<stdio.h>

main()
{
    int op, i, x, cantidad;
    float totalArticulos = 0, totalSemana = 0;

    printf("Dame la cantidad de articulos a meter: ");
    scanf("%d", &x);

    for(i = 1; i <= x; i++)
    {
        printf("\nDame el numero del producto %d: ",i);
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                printf("\ndame la cantidad de articulos vendidos: ");
                scanf("%d", &cantidad);
                totalArticulos = 2.98 * cantidad;
                totalSemana += totalArticulos;

                break;

            case 2:
                printf("\ndame la cantidad de articulos vendidos: ");
                scanf("%d", &cantidad);
                totalArticulos = 4.50 * cantidad;
                totalSemana += totalArticulos;

                break;

            case 3:
                printf("\ndame la cantidad de articulos vendidos: ");
                scanf("%d", &cantidad);
                totalArticulos = 9.98 * cantidad;
                totalSemana += totalArticulos;

                break;

            case 4:
                printf("\ndame la cantidad de articulos vendidos: ");
                scanf("%d", &cantidad);
                totalArticulos = 4.49 * cantidad;
                totalSemana += totalArticulos;
                break;

            case 5:
                printf("\ndame la cantidad de articulos vendidos: ");
                scanf("%d", &cantidad);
                totalArticulos = 6.87 * cantidad;
                totalSemana += totalArticulos;

                break;

            default:
                printf("\nNumero de producto incorrecto");
                break;
        }


    }

    printf("\nEl total de ventas de la semana es: %.2f", totalSemana);

    return 0;



}

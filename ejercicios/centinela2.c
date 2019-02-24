#include<stdio.h>

main()
{
    int count = 0, ban;
    float litGaso, kilometros, resultado = 0, sumRes = 0;

    printf("\n\nDame los litros gastados del automovil (-1 para terminar): ");
    scanf("%f", &litGaso);

    while(litGaso != -1)
    {

        printf("\nDame los kilometros recorridos del automovil: ");
        scanf("%f", &kilometros);
        resultado = kilometros / litGaso;
        printf("\nLos kilometros / litros para este automovil fue: %.2f", resultado);
        sumRes += resultado;
        printf("\nsumres: %.2f", sumRes);
        count ++;
        printf("\ncontador: %d", count);
        printf("\n\nDame los litros gastados del automovil (-1 para terminar): ");
        scanf("%f", &litGaso);

    }

    if(sumRes == 0)
        printf("\nNo hay datos que calcular");
    else
    {
        resultado = sumRes / count;
        printf("\nEl promedio total de kilometros / litros es: %.2f", resultado);

    }


    return 0;

}

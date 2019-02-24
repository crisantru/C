#include<stdio.h>

main()
{
    int valor, valor2, opcion, respuesta, resultado = 0;

    do
    {
        printf("\n   ***OPCIONES***");
        printf("\n1.- PREDECREMENTAR --X");
        printf("\n2.- POSTDECREMENTAR X--");
        printf("\n\nOpcion: ");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\n***Predecrmentar --X");
                printf("\nDame un valor: ");
                scanf("%d", &valor);
                printf("\nresultado = --numero + numero ( variables tienen el valor que introduciste)");
                printf("\ndame el resultado: ");
                scanf("%d", &respuesta);
                resultado = --valor + valor;
                printf("\nResultado: %d", resultado);

                if(resultado == respuesta)
                    printf("\nRESPUESTA CORRECTA");
                else
                    printf("\nRESPUESTA INCORRECTA");
                    printf("\nRESPUESTA: %d", resultado);

                break;

            case 2:
                printf("\n***Postdecrmentar X--");
                printf("\nDame un valor: ");
                scanf("%d", &valor2);
                printf("\nnumero *= valor-- (ambas variables tienen el valor que introduciste) ");
                printf("\ndame el valor resultado: ");
                scanf("%d", &respuesta);
                valor2 *= valor2--;
                printf("\nResultado: %d", valor2);

                if(valor2 == respuesta)
                    printf("\nRESPUESTA CORRECTA\n");
                else
                {
                    printf("\nRESPUESTA INCORRECTA");
                    printf("\nRESPUESTA: %d", resultado);

                }

                break;

        }



    }while(opcion !=3);

    return 0;
}

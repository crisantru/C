#include<stdio.h>

void leerArreglo (int a[][5]);
void visualizarArreglo (int a [][5]);

int main()
{
    int a[3][5];
    leerArreglo(a);
    visualizarArreglo(a);


    return 0;
}

void leerArreglo (int a[][5])
{
    int i, j;

    printf("Introduzca 15 numeros enteros, 5 por fila: \n");

    for(i = 0; i < 3; i++)
    {
        printf("\n\t****Fila %d**** \n", i);
        //printf("\n");

        for(j = 0; j < 5; j++)
        {
            printf("Dato %d: ", j);
            scanf("%d", &a[i][j]);


        }


    }

}

void visualizarArreglo (int a [][5])
{
    int i, j;

    printf("\n\n\tContenido de la Tabla\n");
    for(i = 0; i < 3; i++)
    {

        for(j = 0; j < 5; j++)
        {
            printf("%d \t", a[i][j]);

        }

        printf("\n");

    }



}


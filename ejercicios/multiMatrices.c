#include<stdio.h>

void insertarMatriz(int a[][3]);
void imprimirMatriz(int a[][3]);
void multiplicaMatriz(int a[][3], int b[][3]);


int main()
{
    int a[3][3], b[3][3];

    printf("Matriz 1");
    insertarMatriz(a);
    imprimirMatriz(a);
    printf("\n\nMatriz 2");
    insertarMatriz(b);
    imprimirMatriz(b);
    multiplicaMatriz(a, b);
    //printf("matriz 1: %d", a[0][2]);



    return 0;

}

void insertarMatriz(int a[][3])
{
    int i, j;

    printf("\nInserta los datos de la matriz");
    for(i = 0; i < 3; i++)
    {
        printf("\n\n******Fila %d******", i);

        for(j = 0; j < 3; j++)
        {
            printf("\nDato %d: ", j);
            scanf("%d", &a[i][j]);

        }

    }



}


void imprimirMatriz(int a[][3])
{
    int i,j;

    printf("\n\n\tMatriz\n\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d\t", a[i][j]);

        }
    printf("\n");

    }

}


void multiplicaMatriz(int a[][3], int b[][3])
{
    int c[3][3], i, j;

    //printf("\nmatriz 1: %d", a[1][2]);
    //printf("\nmatriz 2: %d", b[2][1]);

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            c[i][j] = a[i][j] * b[i][j];


        }



    }

    imprimirMatriz(c);

}

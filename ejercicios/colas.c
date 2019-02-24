#include<stdio.h>
#include<stdlib.h>

typedef struct nuevoElemento
{
    char nombrePersona[25];
    char sexo[10];

    struct nuevoElemento *siguiente;

} ELEMENTOCOLA;

typedef struct cola
{
    struct nuevoElemento *frente;
    struct nuevoElemento *final;

} COLA;

int main()
{
    int opcion;

    do{

        printf("\n---------Colas---------");
        printf("\n|1.-Insertar          |");
        printf("\n|2.-Eliminar          |");
        printf("\n|3.-Salir             |");
        printf("\n----------------------|");

        printf("\nElige una opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                break;

            case 2:
                break;

        }

    }while(opcion != 2);


    return 0;
}

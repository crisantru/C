#include<stdio.h>
#include<stdlib.h>


typedef struct elementoPila
{
    int dato;
    struct elementoPila *siguiente;

}   ELEMENTOPILA;

ELEMENTOPILA *mete(ELEMENTOPILA **tope, int dato);
ELEMENTOPILA *push(ELEMENTOPILA **tope, ELEMENTOPILA *nuevoElementoPila);
int saca(ELEMENTOPILA **tope);
int pop(ELEMENTOPILA **tope);
int pilaVacia(ELEMENTOPILA *tope);
void imprimirPila(ELEMENTOPILA *tope);
//int pilaLLena(ELEMENTOPILA *tope);

int main()
{
    int opcion, dato, validaElimina;
    ELEMENTOPILA *validaInserta = NULL;
    ELEMENTOPILA *tope = NULL;

    do
    {
        printf("\n\n  ----------Pila Dinamica-----------");
        printf("\n|  1- Insertar a la Pila              |");
        printf("\n|  2- Quitar de la Pila               |");
        printf("\n|  3- Imprimir Pila                   |");
        printf("\n|  4- Salir                           |");
        printf("\n  -----------------------------------");

        printf("\n\nEscribe Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\n---------Insertar Pila----------");
                printf("\nEscribe el dato para la pila: ");
                scanf("%d", &dato);
                validaInserta = mete(&tope, dato);

                if(validaInserta->dato == dato)
                {
                    printf("\nTu insercion del dato fue correcto");
                    printf("\nDato en la pila: %d", validaInserta->dato);
                }

                else
                    printf("\nHubo un error al meter el dato...");

                if (validaInserta == NULL)
                    printf("\nNose pudo agregar el elemento a tu pila");
                else
                    printf("\nTu dato se ha guardado en la pila...");

                break;

            case 2:
                printf("\n----------Eliminar de la Pila---------");
                validaElimina = saca(&tope);

                if(validaElimina == 1)
                    printf("\nSe saco un elemento de tu pila...");
                else
                    printf("\nHubo un error al hacer pop");

                break;

            case 3:
                printf("\n------Pila-----");
                imprimirPila(tope);
                printf("\n---------------");

                break;

            case 4:

                break;

            default:
                printf("\nOpcion Incorrecta...");
        }

    } while(opcion != 4);

    return 0;

}

ELEMENTOPILA *mete(ELEMENTOPILA **tope, int dato)
{
    ELEMENTOPILA *nuevoElementoPila = NULL;

    if(pilaVacia((*tope)) == 1 || (*tope) != NULL)
    {
        nuevoElementoPila = (ELEMENTOPILA *) malloc(sizeof(ELEMENTOPILA));
        nuevoElementoPila->dato = dato;
        return push(tope, nuevoElementoPila);
    }

    return NULL;

}

ELEMENTOPILA *push(ELEMENTOPILA **tope, ELEMENTOPILA *nuevoElementoPila)
{
    nuevoElementoPila->siguiente = *tope;
    *tope = nuevoElementoPila;

    return nuevoElementoPila;

}

int saca(ELEMENTOPILA **tope)
{

    if(pilaVacia(*tope) == 1)
    {
        printf("\nNo se puede eliminar tu pila esta vacia...");
        return 2;
    }

    return pop(tope);
}

int pop(ELEMENTOPILA **tope)
{

    ELEMENTOPILA *pilaAux = NULL;

    pilaAux = *tope;
    *tope = (*tope)->siguiente;
    pilaAux->siguiente = NULL;

    return 1;
}

void imprimirPila(ELEMENTOPILA *tope)
{
    if(pilaVacia(tope) == 1)
    {
        printf("\nNo se puede imprimir. Tu pila esta vacia...");
        return;
    }

    printf("\nDato: %d", tope->dato);

    if(tope->siguiente == NULL)
        return;

    imprimirPila(tope->siguiente);
}

int pilaVacia(ELEMENTOPILA *tope)
{
    if(tope == NULL)
        return 1;
    return 0;
}


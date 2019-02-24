#include<stdio.h>
#include<stdlib.h>

typedef struct elementoCola
{
    int dato;
    struct elementoCola *siguiente;

} ELEMENTOCOLA;

typedef struct cola
{
    struct elementoCola *frente;
    struct elementoCola *final;

} COLA;

ELEMENTOCOLA *insertarCola(COLA *cola, int dato);
int colaVacia(COLA *cola);
void imprimirCola(ELEMENTOCOLA *cola, ELEMENTOCOLA *elemenAux);
int eliminaElementoCola(COLA *cola);

int main()
{
    int opcion, dato, validaEliminar;
    ELEMENTOCOLA *validaInserta = NULL;
    COLA *cola = NULL;
    cola = (COLA *) malloc(sizeof(COLA));

    do
    {
        printf("\n\n------Cola Circular------");
        printf("\n1.-Introducir a la cola   |");
        printf("\n2.-Quitar de la cola      |");
        printf("\n3.-Imprimir               |");
        printf("\n4.-Salir                  |");
        printf("\n---------------------------");

        printf("\n\nElige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\nDame el dato a insertar en la cola: ");
                scanf("%d", &dato);
                validaInserta = insertarCola(cola, dato);
                printf("\ndato: %d", validaInserta->dato);

                if(cola->final->siguiente == cola->frente)
                {
                    printf("\ntu insertar a la cola circular se realizo correctamente");

                }
                break;

            case 2:
                validaEliminar = eliminaElementoCola(cola);
                printf("\n\n------Datos en Cola------");
                imprimirCola(cola->frente, cola->frente);
                printf("\n\n-------------------------");

                if(validaEliminar == 1)
                    printf("\nSe elimino correctamente...");
                else
                    printf("\nHubo un problema el tratar de eliminar...");

                break;

            case 3:
                printf("\n\n------Datos en Cola------");
                imprimirCola(cola->frente, cola->frente);
                printf("\n\n-------------------------");
                break;

            case 4:
                break;

            default:
                puts("Error de opcion...");
        }

    } while(opcion !=4);

    return 0;

}

ELEMENTOCOLA *insertarCola(COLA *cola, int dato)
{
    ELEMENTOCOLA *nuevoElementoCola = NULL;

    nuevoElementoCola = (ELEMENTOCOLA *) malloc(sizeof(ELEMENTOCOLA));

    if(nuevoElementoCola == NULL)
    {
        printf("\nError de alojamiento de memoria.");
        return;

    }

    nuevoElementoCola->dato = dato;     //asigna el valor de dato a la cola

    if(colaVacia(cola) == 1)
    {
        cola->frente = nuevoElementoCola;
        cola->final =nuevoElementoCola;
        nuevoElementoCola->siguiente = cola->frente;
        return;

    }



    if(colaVacia(cola) == 0)
    {
        cola->final->siguiente = nuevoElementoCola;
        cola->final = nuevoElementoCola;
        nuevoElementoCola->siguiente = cola->frente;
        return;

    }

    return nuevoElementoCola;
}

int colaVacia(COLA *cola)
{
    if(cola->frente == NULL && cola->final == NULL)
        return 1;
    return 0;

}

void imprimirCola(ELEMENTOCOLA *cola, ELEMENTOCOLA *elemenAux)
{

    if(cola == NULL)
    {
        printf("\nTu cola esta vacia nada que imprimir....");
        return;
    }


    printf("\nDato: %d", cola->dato);

    if(cola->siguiente == elemenAux)
        return;

    imprimirCola(cola->siguiente, elemenAux);

}

int eliminaElementoCola(COLA *cola)
{
    ELEMENTOCOLA *elementoAux = NULL;

    if(colaVacia(cola) == 1)
    {
        printf("\nNo se puede eliminar. La cola esta vacia...");
        return;
    }


    elementoAux = cola->frente;
    cola->frente = cola->frente->siguiente;
    cola->final->siguiente = cola->frente;
    free(elementoAux);
    return 1;

}

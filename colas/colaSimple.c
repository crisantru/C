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
int eliminarElementoCola(COLA *cola);
int colaVacia(COLA *cola);
void imprimirCola(ELEMENTOCOLA *cola);

int main()
{
    int opcion, dato, validaElimina;
    COLA *cola = NULL;
    ELEMENTOCOLA *validaInsertar;

    cola = (COLA *) malloc(sizeof(COLA));

    do
    {
        printf("\n\n------Cola Simple------");
        printf("\n1.-Introducir a la cola |");
        printf("\n2.-Quitar de la cola    |");
        printf("\n3.-Imprimir             |");
        printf("\n4.-Salir                |");
        printf("\n-------------------------");

        printf("\n\nElige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                            //insertar
                printf("\nDame el dato a poner en la cola: ");
                scanf("%d", &dato);
                validaInsertar = insertarCola(cola, dato);
                if(validaInsertar->dato == dato)
                {
                    printf("\nTu dato se coloco correctamente en la cola...");
                    printf("\ndato: %d", validaInsertar->dato);
                }

                else
                    printf("\nHubo un error en la inserccion...");


                break;

            case 2:
                            //eliminar

                validaElimina = eliminarElementoCola(cola);

                if(validaElimina == 1)
                    printf("\nTu dato se elimino correctamente de la cola...");

                break;

            case 3:
                            //imprimir
                printf("\n\n------Datos en Cola------");
                imprimirCola(cola->frente);
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


    if(cola == NULL)
    {
        printf("\nError de alojamiento memoria...");
        return;

    }

    nuevoElementoCola->dato = dato;

    if(colaVacia(cola) == 1)
    {
        cola->frente = nuevoElementoCola;
        cola->final = nuevoElementoCola;
        nuevoElementoCola->siguiente = NULL;
        return;
    }


    if(colaVacia(cola) == 0)
    {
        cola->final->siguiente = nuevoElementoCola;
        cola->final = nuevoElementoCola;
        nuevoElementoCola->siguiente = NULL;
        return;

    }

    return nuevoElementoCola;


}

int eliminarElementoCola(COLA *cola)
{

    ELEMENTOCOLA *elementoAux = NULL;

    if(colaVacia(cola) == 1)
    {
        printf("\nLo siento no se puede eliminar tu cola esta vacia...");
        return;
    }

    elementoAux = cola->frente;
    cola->frente = cola->frente->siguiente;
    free(elementoAux);
    return 1;


    return 0;
}

int colaVacia(COLA *cola){
    if(cola->frente == NULL && cola->final == NULL)
        return 1;

    return 0;

}

void imprimirCola(ELEMENTOCOLA *cola)
{

    if(cola == NULL)
    {
        printf("\nTu cola esta vacia nada que imprimir....");
        return;
    }

    printf("\nDato: %d", cola->dato);

    if(cola->siguiente == NULL)
        return;

    imprimirCola(cola->siguiente);

}

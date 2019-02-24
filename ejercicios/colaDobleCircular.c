#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct elementoCola
{
    int dato;
    struct elementoCola *siguiente;
    struct elementoCola *anterior;

} ELEMENTOCOLA;

typedef struct cola
{
    struct elementoCola *frente;
    struct elementoCola *final;

} COLA;

ELEMENTOCOLA *insertarCola(COLA *cola, int dato);
int insertarElemenA(COLA *cola, ELEMENTOCOLA *nuevoElemento);
int insertarElemenD(COLA *cola, ELEMENTOCOLA *nuevoElemento);

int colaVacia(COLA *cola);
void imprimirCola(ELEMENTOCOLA *cola, ELEMENTOCOLA *elemenAux);
//int eliminaElementoCola(COLA *cola);

int main()
{
    int opcion, dato, validaEliminar;
    ELEMENTOCOLA *validaInserta = NULL;

    COLA *cola = NULL;
    cola = (COLA *) malloc(sizeof(COLA));

    do
    {
        printf("\n\n-------Cola Doble Circular--------");
        printf("\n1.-Introducir a la cola            |");
        printf("\n2.-Quitar de la cola               |");
        printf("\n3.-Imprimir                        |");
        printf("\n4.-Salir                           |");
        printf("\n------------------------------------");

        printf("\n\nElige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("\nDame el dato a insertar en la cola: ");
                scanf("%d", &dato);
                validaInserta = insertarCola(cola, dato);
                printf("\ndato: %d", validaInserta->dato);

                if(validaInserta->dato == dato)
                    printf("\nSu inserccion finalizo adecuadamente");

                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            default:
                puts("Error de opcion...");

        }
    } while(opcion != 4);

    return 0;
}

ELEMENTOCOLA *insertarCola(COLA *cola, int dato)
{
    int validaInsert;
    char respuesta;
    ELEMENTOCOLA *nuevoElementoCola ;

    nuevoElementoCola = (ELEMENTOCOLA *) malloc(sizeof(ELEMENTOCOLA));

    if(nuevoElementoCola == NULL)
    {
        printf("\nError de alojamiento de memoria.");
        return;

    }

    nuevoElementoCola->dato = dato;

    if(colaVacia(cola) == 1)
    {
        printf("\nentra if colaVacia");
        printf("\nentra a insertar por primera vez");
        cola->frente = nuevoElementoCola;
        cola->final = nuevoElementoCola;
        nuevoElementoCola->anterior = nuevoElementoCola;
        nuevoElementoCola->siguiente =nuevoElementoCola;
        return;

    }
    printf("\nsale if colaV");

    if(colaVacia(cola) == 0)
    {
        printf("\nentra insercion de mas de uno");
        printf("\nPor donde quieres insertar, adelante o detras?...(A/D): ");
        fflush(stdout);
        scanf("%c", &respuesta);
        printf("\nentra insercion de mas de uno 2");

        if(respuesta == 'A' || respuesta == 'a')
        {
            printf("\nentra if respuesta");
            validaInsert = insertarElemenA(cola, nuevoElementoCola);
            if(validaInsert == 1)
            {
                printf("\nSe inserto correctamente el nuevo elemento adelante...");
                return;

            }
            return;
        }

        if(respuesta == 'D' || respuesta == 'd')
        {
            validaInsert = insertarElemenD(cola, nuevoElementoCola);
            if(validaInsert == 2)
            {
                printf("\nSe inserto correctamente el nuevo elemento por detras(default)");
                return;

            }

            return;
        }

        return;
    }

    return nuevoElementoCola;

}

int insertarElemenA(COLA *cola, ELEMENTOCOLA *nuevoElemento)
{

    nuevoElemento->anterior = cola->final;
    nuevoElemento->siguiente = cola->frente;
    cola->frente = nuevoElemento;
    cola->final->siguiente = nuevoElemento;
    return 1;


}

int insertarElemenD(COLA *cola, ELEMENTOCOLA *nuevoElemento)
{
    nuevoElemento->siguiente = cola->frente;
    nuevoElemento->anterior = cola->final;
    cola->final->siguiente = nuevoElemento;
    cola->final = nuevoElemento;
    cola->frente->anterior = nuevoElemento;
    return 2;

}

void imprimirCola(ELEMENTOCOLA *cola, ELEMENTOCOLA *elemenAux)
{

    if(cola == NULL)
        return;

    printf("\nDato: %d", cola->dato);

    if(cola->siguiente == elemenAux)
        return;

    imprimirCola(cola->siguiente, elemenAux);

}

int colaVacia(COLA *cola)
{
    if(cola->frente == NULL && cola->final == NULL)
        return 1;
    return 0;

}

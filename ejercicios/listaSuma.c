#include<stdio.h>
#include<stdlib.h>

typedef struct elementoLista
{
    int dato;
    struct elementoLista *siguiente;

} ELEMENTOLISTA;

ELEMENTOLISTA* insertarElemLista(ELEMENTOLISTA **inicio, int dato);
int sumaElemLista(ELEMENTOLISTA *inicio, int suma);
int mulElemLista(ELEMENTOLISTA *inicio);
void imprimirLista(ELEMENTOLISTA *inicio);

int main()
{
    int dato, opcion, suma = 0, resultadoSuma = 0;
    ELEMENTOLISTA *inicio = NULL;
    ELEMENTOLISTA *validaInsertar = NULL;

    do
    {
        printf("\n\n----------lista-----------");
        printf("\n1.-Insertar               |");
        printf("\n2.-Sumar lista            |");
        printf("\n3.-Multiplicar lista      |");
        printf("\n4.-Ver lista              |");
        printf("\n---------------------------");

        printf("\nDame la opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                 printf("\nDame el dato a insertar: ");
                 scanf("%d", &dato);
                 validaInsertar = insertarElemLista(&inicio, dato);

                 if(validaInsertar->dato == dato)
                    printf("\nTu dato se inserto correctamente...");

                break;

            case 2:
                printf("\n-------Tu lista-------");
                imprimirLista(inicio);
                resultadoSuma = sumaElemLista(inicio, suma);
                printf("\nLa suma de los elementos de tu lista es: %d", resultadoSuma);

                break;

            case 3:
                printf("\n-------Tu lista-------");
                imprimirLista(inicio);
                resultadoSuma = mulElemLista(inicio);
                printf("\nLa multiplicacion de los elementos de tu lista es: %d", resultadoSuma);

                break;

            case 4:
                printf("\n-------Tu lista-------");
                imprimirLista(inicio);
                printf("\n----------------------");

                break;
            default:
                printf("\nOpcion incorrecta");


        }






    } while(opcion != 3);

    return 0;

}


ELEMENTOLISTA* insertarElemLista(ELEMENTOLISTA **inicio, int dato)
{

    ELEMENTOLISTA *nodo;
    nodo = (ELEMENTOLISTA *) malloc(sizeof(ELEMENTOLISTA));

    if(nodo == NULL)
    {
        printf("\nError de asignacion de memoria.");
        return;
    }

    nodo->dato = dato;
    nodo->siguiente = *inicio;
    *inicio = nodo;



    return nodo;

}

int sumaElemLista(ELEMENTOLISTA *inicio, int suma)
{
    int sumaAux = 0;

    printf("\nsuma entrante: %d", sumaAux);

    if(inicio->siguiente == NULL)
    {
        printf("\n\nentra if paro");
        return 0;
    }
    printf("\nsale if de paro");

    sumaAux = sumaAux + inicio->dato;
    printf("\nsuma al operar: %d", sumaAux);

    sumaElemLista(inicio->siguiente, sumaAux);

    return sumaAux;





}

int mulElemLista(ELEMENTOLISTA *inicio)
{

    int sumaDatosList = 0;

    if(listaVacia(inicio) == 1)
        return 0;


   sumaDatosList = inicio->dato * inicio->dato;
   mulElemLista(inicio->siguiente);

   return sumaDatosList;

}


void imprimirLista(ELEMENTOLISTA *inicio)
{

    if(listaVacia(inicio) == 1)
    {
        printf("\nTu lista esta vacia...");
        return;
    }

    printf("\nDato: %d", inicio->dato);

    if(inicio->siguiente == NULL)
        return;

    imprimirLista(inicio->siguiente);
}

int listaVacia(ELEMENTOLISTA *inicio)
{
    if(inicio == NULL)
        return 1;

    return 0;

}

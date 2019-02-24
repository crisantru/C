#include<stdio.h>
#include<stdlib.h>
/*Falta funcion de imprimir hacia delante e imprimir desde atras*/

typedef struct elementoLista
{
    int dato;
    struct elementoLista *anterior;
    struct elementoLista *siguiente;

} ELEMENTOLISTA;

int insertarElementoLista(ELEMENTOLISTA **inicio, int dato);
int eliminarElementoLista(ELEMENTOLISTA **inicio, int dato);
int ordenaElementoLista(ELEMENTOLISTA *nuevoElemento, ELEMENTOLISTA **inicio);
//void buscarElementoLista(ELEMENTOLISTA *inicio, int dato);
void imprimirLista(ELEMENTOLISTA *inicio);

int main()
{
    int opcion, dato, validaInsertar, validaElimina;

    ELEMENTOLISTA *inicio = NULL;


    do
    {

        printf("\n\n-------Opciones de Lista-------\n");
        printf("1.-Insertar                   |\n");
        printf("2.-Eliminar                   |\n");
        printf("3.-Buscar                     |\n");
        printf("4.-Imprimir                   |\n");
        printf("5.-Salir                      |\n");
        printf("______________________________|\n\n");
        printf("\nEscoge una opcion: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
                printf("\nDame el dato a insertar en la lista: ");
                scanf("%d", &dato);
                validaInsertar = insertarElementoLista(&inicio, dato);
                if(validaInsertar == 1)
                {
                    printf("\nSe inserto correctamente");
                    printf("\nDato: %d", inicio->dato);

                }

                else
                    printf("\nHubo un error al insertar");

                break;

            case 2:

                printf("\n--------Tu Lista--------");
                imprimirLista(inicio);
                printf("\n------------------------");
                printf("\nEscribe el dato a eliminar: ");
                scanf("%d", &dato);
                validaElimina = eliminarElementoLista(&inicio, dato);

                if(validaElimina == 1)
                {
                    printf("Tu dato fue eliminado exitosamente...");
                }

                break;

            case 3:

                break;

            case 4:
                printf("\n--------Tu Lista--------");
                imprimirLista(inicio);
                printf("\n------------------------");
                break;

            default:
                puts("Error de opcion.");


            }

    }while(opcion != 5);



    return 0;
}

int insertarElementoLista(ELEMENTOLISTA **inicio, int dato)
{

    ELEMENTOLISTA *nuevoElementoLista;
    nuevoElementoLista = (ELEMENTOLISTA*) malloc(sizeof(ELEMENTOLISTA));

    if(nuevoElementoLista == NULL)
    {
        printf("\nError de alojamiento de memoria...");
        return 0;
    }

    nuevoElementoLista->dato = dato;

    if(*inicio == NULL)
    {
        printf("\nentra insertar por primera vez");
        *inicio = nuevoElementoLista;
        nuevoElementoLista->siguiente = NULL;
        nuevoElementoLista->anterior = NULL;
        return 1;
    }
    printf("\nsale if insertar por primera vez");

    return ordenaElementoLista(nuevoElementoLista, inicio);

}

int ordenaElementoLista(ELEMENTOLISTA *nuevoElemento, ELEMENTOLISTA **inicio)
{
    if((*inicio)->dato >= nuevoElemento->dato)
    {
        printf("/nEntra a insertar a partir del primero");
        nuevoElemento->siguiente = *inicio;
        nuevoElemento->anterior = NULL;
        (*inicio)->anterior = nuevoElemento;
        *inicio = nuevoElemento;
        return 1;
    }


    if((*inicio)->siguiente == NULL)
    {
        nuevoElemento->siguiente = (*inicio)->siguiente;
        (*inicio)->siguiente = nuevoElemento;
        nuevoElemento->anterior = *inicio;
        return 1;


    }

    ordenaElementoLista(nuevoElemento, &((*inicio)->siguiente));
}

int eliminarElementoLista(ELEMENTOLISTA **inicio, int dato)
{
    ELEMENTOLISTA *elementoActual;

    if(*inicio == NULL)
    {
        printf("No se pudo eliminar tu dato solicitado. Checa en tu lista si se encuentra el dato");
        return 0 ;
    }

    if((*inicio)->dato == dato)
    {
        elementoActual = *inicio;
        *inicio = (*inicio)->siguiente;
        free(elementoActual);
        return 1;
    }

    eliminarElementoLista(&((*inicio)->siguiente), dato);

}


void imprimirLista(ELEMENTOLISTA *inicio)
{
     if(inicio == NULL)
    {
        printf("\nNo se puede imprimir. Tu lista esta vacia...");
        return;
    }
    printf("\nDato: %d", inicio->dato);

    if(inicio->siguiente == NULL)
        return;

    imprimirLista(inicio->siguiente);

}

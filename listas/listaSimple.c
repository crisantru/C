#include<stdio.h>
#include<stdlib.h>


typedef struct elementoLista
{
    int dato;
    struct elementoLista *siguiente;

} ELEMENTOLISTA;

ELEMENTOLISTA* insertarElementoLista(ELEMENTOLISTA **inicio, int dato);
int eliminarElementoLista(ELEMENTOLISTA **inicio, int dato);
void buscarElementoLista(ELEMENTOLISTA *inicio, int dato);
void imprimirLista(ELEMENTOLISTA *inicio);
void vaciarLista(ELEMENTOLISTA **inicio);

int main()
{
    int opcion, dato, validaElimina;
    char visualisar;
    ELEMENTOLISTA *inicio = NULL;
    ELEMENTOLISTA *validaInsertar = NULL;


    do
    {

        printf("\n\n-------Opciones de Lista-------\n");
        printf("1.-Insertar                   |\n");
        printf("2.-Eliminar                   |\n");
        printf("3.-Buscar                     |\n");
        printf("4.-Imprimir                   |\n");
        printf("5.-Vaciar Lista               |\n");
        printf("6.-Salir                      |\n");
        printf("______________________________|\n\n");
        printf("\nEscoge una opcion: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:     //insertar
                printf("\nEscribe el dato a insertar: ");
                scanf("%d", &dato);
                validaInsertar = insertarElementoLista(&inicio, dato);

                if(validaInsertar->dato == inicio->dato)
                {
                    printf("\nTu dato fue insertado exitosamente...");
                }
                else
                    printf("\nNose pudo insetar tu dato");
                break;

            case 2:     //eliminar
                printf("\n--------Tu Lista--------");
                imprimirLista(inicio);
                printf("\n------------------------");
                printf("\nEscribe el dato a eliminar: ");
                scanf("%d", &dato);
                validaElimina = eliminarElementoLista(&inicio, dato);

                if(validaElimina == 1)
                {
                    printf("\nTu dato fue eliminado exitosamente...");
                }

                break;

            case 3:     //buscar
                printf("\nQue dato quieres buscar: ");
                scanf("%d", &dato);
                buscarElementoLista(inicio, dato);
                break;

            case 4:     //imprimir
                printf("\n--------Tu Lista--------");
                imprimirLista(inicio);
                printf("\n------------------------");

                break;
            case 5:

                vaciarLista(&inicio);

                break;
            case 6:
                break;

            default:
                puts("\nError de opcion.");


            }

    }while(opcion != 6);



    return 0;
}

ELEMENTOLISTA* insertarElementoLista(ELEMENTOLISTA **inicio, int dato)
{
    ELEMENTOLISTA *nuevoElemento;


    nuevoElemento = (ELEMENTOLISTA *) malloc(sizeof(ELEMENTOLISTA));

    if(nuevoElemento == NULL)
    {
        puts("\nFin de ejecucion. Error de asignacion de memoria");
        exit(-1);

    }

    nuevoElemento->dato = dato;

    nuevoElemento->siguiente = *inicio;
    *inicio = nuevoElemento;

    return nuevoElemento;

}

int eliminarElementoLista(ELEMENTOLISTA **inicio, int dato)
{
    ELEMENTOLISTA *elementoActual;

    if(*inicio == NULL)
    {
        printf("\nNo se pudo eliminar tu dato solicitado. Checa en tu lista si se encuentra el dato");
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

void buscarElementoLista(ELEMENTOLISTA *inicio, int dato)
{
    if(inicio == NULL)
    {
        printf("\nLo siento tu elemento deseado no se encuentra...");
        return ;
    }

    if(inicio->dato == dato)
    {
        printf("\nTu dato si esta disponible y se encuentra en la direccion: %p", &inicio->dato);
        return ;
    }

    buscarElementoLista(inicio->siguiente, dato);

}

void vaciarLista(ELEMENTOLISTA **inicio)
{
    ELEMENTOLISTA *elementoAux;

    if(*inicio == NULL)
    {
        printf("Tu lista esta vacia");
        return ;

    }


    if((*inicio)->siguiente != NULL || (*inicio)->siguiente == NULL)
    {
        elementoAux = *inicio;
        *inicio = (*inicio)->siguiente;
        free(elementoAux);

    }

    vaciarLista(inicio);

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


#include<stdio.h>
#include<stdlib.h>


typedef struct elementoLista
{
    int dato;
    struct elementoLista *siguiente;

} nodo;

void insertarElementoLista(nodo **inicio, int dato);
void eliminarElementoLista(nodo **inicio, int dato);
void buscarElementoLista(nodo *inicio, int dato);
void imprimirLista(nodo *inicio);

int main()
{
    int opcion, dato;
    char visualisar;
    nodo *inicio = NULL;


    do
    {

        printf("\n-------Opciones de Lista-------\n");
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
                printf("\nEscribe el dato a insertar: ");
                scanf("%d", &dato);
                insertarElementoLista(&inicio, dato);
                break;

            case 2:
                printf("\n--------Tu Lista--------");
                imprimirLista(inicio);
                printf("\n------------------------");
                printf("\nEscribe el dato a eliminar: ");
                scanf("%d", &dato);
                eliminarElementoLista(&inicio, dato);
                break;

            case 3:
                printf("Que dato quieres buscar: ");
                scanf("%d", &dato);
                buscarElementoLista(inicio, dato);
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

void insertarElementoLista(nodo **inicio, int dato)
{
    nodo *nuevoElemento;


    nuevoElemento = (nodo *) malloc(sizeof(nodo));

    if(nuevoElemento == NULL)
    {
        puts("Fin de ejecucion. Error de asignacion de memoria");
        exit(-1);

    }

    nuevoElemento->dato = dato;

    nuevoElemento->siguiente = *inicio;
    *inicio = nuevoElemento;


}

void eliminarElementoLista(nodo **inicio, int dato)
{
    nodo *elementoActual;

    if(*inicio == NULL)
    {
        printf("\n Lo siento tu lista esta vacia...");
        return ;
    }

    if((*inicio)->dato == dato)
    {
        elementoActual = *inicio;
        *inicio = (*inicio)->siguiente;
        free(elementoActual);
        return ;
    }

    eliminarElementoLista(&((*inicio)->siguiente), dato);

}

void buscarElementoLista(nodo *inicio, int dato)
{
    if(inicio == NULL)
    {
        printf("\nLo siento tu elemento deseado no se encuentra...");
        return ;
    }

    if(inicio->dato == dato)
    {
        printf("Tu dato si esta disponible y se encuentra en la direccion: %p\n", &inicio->dato);
        return ;
    }

    buscarElementoLista(inicio->siguiente, dato);

}

void imprimirLista(nodo *inicio)
{

    while(inicio != NULL)
    {
        printf("\n%d", inicio->dato);
        inicio = inicio->siguiente;


    }


}

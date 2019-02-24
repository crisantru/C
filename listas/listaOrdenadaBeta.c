#include<stdio.h>
#include<stdlib.h>


typedef struct elementoLista
{
    int dato;
    struct elementoLista *siguiente;

} nodo;

int insertarElementoLista(nodo **inicio, int dato);
int eliminarElementoLista(nodo **inicio, int dato);
int ordenaElementoLista(nodo **nuevoElemento, nodo **inicio);
void buscarElementoLista(nodo *inicio, int dato);
void imprimirLista(nodo *inicio);

int main()
{
    int opcion, dato, validaElimina;
    char visualisar;
    nodo *inicio = NULL;
    nodo *validaInsertar = NULL;


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
                printf("\nEscribe el dato a insertar: ");
                scanf("%d", &dato);
                validaInsertar = insertarElementoLista(&inicio, dato);

                if(validaInsertar == 1)
                {
                    printf("\nTu dato fue insertado exitosamente...");
                    //return ;
                }

                if(validaInsertar == 3)
                {
                    printf("\nTu elemento se inserto correctamente. Es mayor y se inserto al final de la lista...");
                    //return ;
                }

                if(validaInsertar == 2)
                {
                    printf("\nTu elemento se inserto correctamente. Es menor o igual y se inserto al principio de la lista...");
                    //return ;

                }
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

int insertarElementoLista(nodo **inicio, int dato)
{
    nodo *nuevoElemento;
    nuevoElemento = (nodo *) malloc(sizeof(nodo));

    if(nuevoElemento == NULL)
    {
        puts("Fin de ejecucion. Error de asignacion de memoria");
        exit(-1);

    }

    nuevoElemento->dato = dato;
    return ordenaElementoLista(&nuevoElemento, inicio);

}

int ordenaElementoLista(nodo **nuevoElemento, nodo **inicio)
{
    if( *inicio == NULL)
    {
        (*nuevoElemento)->siguiente = *inicio;
        *inicio = *nuevoElemento;
        return 1;
    }

    if((*nuevoElemento)->dato <= (*inicio)->dato)
    {
        (*nuevoElemento)->siguiente = *inicio;
        *inicio = *nuevoElemento;
        return 2;
    }

    if((*inicio)->siguiente == NULL)
    {
        (*nuevoElemento)->siguiente = (*inicio)->siguiente;
        (*inicio)->siguiente = *nuevoElemento;
        return 3;
    }

    ordenaElementoLista(nuevoElemento, &((*inicio)->siguiente));

}

int eliminarElementoLista(nodo **inicio, int dato)
{
    nodo *elementoActual;

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

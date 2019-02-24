#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct elementoLista
{

    char nombre[20];
    char apellidoPaterno[15];
    char apellidoMaterno[15];
    int edad;

    struct elementoLista *siguiente;

} nodo;

struct nodo* insertarElementoLista(nodo **inicio, char nombreAlumno[20], char apellidoPaterno[15], char apellidoMaterno[15], int edad);
int eliminarElementoLista(nodo **inicio, char nombreAlumno[20]);
void buscarElementoLista(nodo *inicio, char nombreAlumno[20]);
void imprimirLista(nodo *inicio);
void vaciarLista(nodo **inicio);

int main()
{
    int opcion, validaElimina, edad;
    char nombreAlumno[20], apellidoPaterno[15], apellidoMaterno[15];
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
        printf("5.-Vaciar Lista               |\n");
        printf("6.-Salir                      |\n");
        printf("______________________________|\n\n");
        printf("\nEscoge una opcion: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:           //Insertar
                printf("\nDame el nombre de tu Alumno: ");
                fflush(stdout);
                scanf (" %[^\n]%*c", nombreAlumno);
                printf("\nDame el apellido Paterno: ");
                fflush(stdout);
                scanf ("%[^\n]%*c", apellidoPaterno);
                printf("\nDame el apellido Materno: ");
                fflush(stdout);
                scanf ("%[^\n]%*c", apellidoMaterno);
                printf("\nDame su edad: ");
                fflush(stdout);
                scanf ("%d", &edad);

                validaInsertar = insertarElementoLista(&inicio, nombreAlumno, apellidoPaterno, apellidoMaterno, edad);

                if(validaInsertar->nombre == inicio->nombre)
                {
                    printf("\nTu dato fue insertado exitosamente...");

                }


                break;

            case 2:             //Eliminar
                printf("\n--------Tu Lista--------------");
                imprimirLista(inicio);
                printf("\n------------------------------");
                printf("\nEscribe el nombre del Alumno a eliminar: ");
                fflush(stdout);
                scanf (" %[^\n]%*c", nombreAlumno);



                validaElimina = eliminarElementoLista(&inicio, nombreAlumno);

                if(validaElimina == 1)
                {
                    printf("Tu dato fue eliminado exitosamente...");
                }

                break;

            case 3:             //Buscar
                printf("Que Alumno quieres buscar: ");
                fflush(stdout);
                scanf (" %[^\n]%*c", nombreAlumno);
                buscarElementoLista(inicio, nombreAlumno);
                break;

            case 4:             //Imprimir
                printf("\n--------Tu Lista--------------");
                imprimirLista(inicio);
                printf("\n------------------------------");

                break;

            case 5:             //vaciarLista
                vaciarLista(&inicio);
                break;

            case 6:

                break;

            default:
                puts("Error de opcion.");


            }

    }while(opcion != 6);



    return 0;
}

struct nodo* insertarElementoLista(nodo **inicio, char nombreAlumno[20], char apellidoPaterno[15], char apellidoMaterno[15], int edad)
{
    nodo *nuevoElemento;
    nuevoElemento = (nodo *) malloc(sizeof(nodo));

    if(nuevoElemento == NULL)
    {
        puts("Fin de ejecucion. Error de asignacion de memoria");
        exit(-1);

    }

    strcpy(nuevoElemento->nombre, nombreAlumno);
    strcpy(nuevoElemento->apellidoPaterno, apellidoPaterno);
    strcpy(nuevoElemento->apellidoMaterno, apellidoMaterno);
    nuevoElemento->edad = edad;

    nuevoElemento->siguiente = *inicio;
    *inicio = nuevoElemento;

    return nuevoElemento;

}


int eliminarElementoLista(nodo **inicio, char nombreAlumno[20])
{
    nodo *elementoActual;

    if(*inicio == NULL)
    {
        printf("No se pudo eliminar tu dato solicitado. Checa en tu lista si se encuentra el dato");
        return 0 ;
    }

    if(strcmp((*inicio)->nombre, nombreAlumno) == 0)
    {
        elementoActual = *inicio;
        *inicio = (*inicio)->siguiente;
        free(elementoActual);
        return 1;
    }

    eliminarElementoLista(&((*inicio)->siguiente), nombreAlumno);



}

void buscarElementoLista(nodo *inicio, char nombreAlumno[20])
{
    if(inicio == NULL)
    {
        printf("\nLo siento tu elemento deseado no se encuentra...");
        return ;
    }

    if(strcmp(inicio->nombre, nombreAlumno) == 0)
    {
        printf("Tu dato si esta disponible y se encuentra en la direccion: %p\n", &inicio->nombre);
        return ;
    }

    buscarElementoLista(inicio->siguiente, nombreAlumno);

}

void imprimirLista(nodo *inicio)
{
    int i = 1;

    while(inicio != NULL)
    {
        printf("\nAlumno %d: %s %s %s edad: %d", i, inicio->nombre, inicio->apellidoPaterno, inicio->apellidoMaterno, inicio->edad);
        inicio = inicio->siguiente;
        i++;
    }

}


void vaciarLista(nodo **inicio)
{
    nodo *elementoAux;

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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Elemento
{
    char nombrePersona[25];
    char ciudadOrigen[10];

    struct Elemento *siguiente;

} ELEMENTOCOLA;

typedef struct cola
{
    struct Elemento *frente;
    struct Elemento *final;

} COLA;

ELEMENTOCOLA *insertarCola(char nombrePersona[25], char ciudadOrigen[20], COLA *cola);
int eliminaCola(COLA *cola);
void imprimirCola(ELEMENTOCOLA *cola);
int colaVacia(COLA *nuevoElemCola);

int main()
{
    int opcion, validaE;
    char opcionE;
    char nombrePersona[25];
    char ciudadOrigen[20];
    COLA *cola;
    cola = (COLA *) malloc(sizeof(COLA));
    ELEMENTOCOLA *validaInserCola;

    if(cola == NULL)
    {
        printf("Error de alojamiento de memoria...");
        return;
    }

    cola->frente = NULL;
    cola->final = NULL;


    do{

        printf("\n\n---------Colas-----------");
        printf("\n1.-Introducir a la cola |");
        printf("\n2.-Quitar de la cola    |");
        printf("\n3.-Imprimir             |");
        printf("\n4.-Salir                |");
        printf("\n-------------------------");

        printf("\n\nElige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:             //insertar
                printf("Escribe el nombre de la persona: ");
                fflush(stdout);
                scanf (" %[^\n]%*c", nombrePersona);
                printf("Escribe su ciudad de origen: ");
                fflush(stdout);
                scanf (" %[^\n]%*c", ciudadOrigen);
                validaInserCola = insertarCola(nombrePersona, ciudadOrigen, cola);

                if(strcmp(validaInserCola->nombrePersona,nombrePersona) == 0)
                    printf("\nTu elemento a la cola fue insertado exitosamente...");
                else
                    printf("\nError. No se pudo Insertar...");

                break;

            case 2:             //Eliminar
                printf("\n¿Quieres liberar a la persona actual de la cola?(S/N):");
                scanf("%s", &opcionE);
                if(opcionE == 'S' || opcionE == 's')
                {
                    validaE = eliminaCola(cola);

                    if(validaE == 0)
                    {
                        printf("\nNo se pudo eliminar de la cola. Tu cola esta vacia");
                    }

                    if(validaE == 1)
                    {
                        printf("\nUna Persona termino y salio de la cola...");
                    }


                }
                else if(opcionE == 'N' || opcionE == 'n')
                    break;

                else
                    printf("\nOpcion incorrecta");
                break;

            case 3:             //Imprimir
                printf("\n\n-------Personas en Cola-------");
                imprimirCola(cola->frente);
                printf("\n\n------------------------------");
                break;

            case 4:
                break;

            default:
                puts("Error de opcion...");

        }

    }while(opcion != 4);


    return 0;
}

ELEMENTOCOLA *insertarCola(char nombrePersona[25], char ciudadOrigen[20], COLA *cola){
    ELEMENTOCOLA *nuevoElemCola;
    nuevoElemCola = (ELEMENTOCOLA *) malloc(sizeof(ELEMENTOCOLA));


    if(nuevoElemCola == NULL)
    {
        printf("Error de alojamiento de memoria...");
        return;

    }

    strcpy(nuevoElemCola->nombrePersona, nombrePersona);
    strcpy(nuevoElemCola->ciudadOrigen, ciudadOrigen);

    if(colaVacia(cola) == 1)
    {
        cola->frente = nuevoElemCola;
        cola->final = nuevoElemCola;
        nuevoElemCola->siguiente = NULL;

        return;
    }

    if(colaVacia(cola) == 0)
    {
        cola->final->siguiente = nuevoElemCola;
        cola->final = nuevoElemCola;
        nuevoElemCola->siguiente = NULL;

        return;

    }

    return nuevoElemCola;
}

int colaVacia(COLA *cola){
    if(cola->frente == NULL && cola->final == NULL)
        return 1;

    return 0;

}

int eliminaCola(COLA *cola)
{
    printf("\nentra a elimina");
    ELEMENTOCOLA *elemColaAux;


    if(colaVacia(cola) == 1)
    {
        printf("\nentra if de cola vacia");
        return 0;
    }

    printf("\nsale if cola vacia");

    elemColaAux = cola->frente;
    cola->frente = cola->frente->siguiente;
    free(elemColaAux);
    printf("\nva a retornar");
    printf("\npersona: %s", cola->frente->nombrePersona);

    return 1;
}

void imprimirCola(ELEMENTOCOLA *cola){


    if(cola == NULL)
    {
        printf("\nNo se puede imprimir no hay nadie en la cola...");
        return;
    }

    printf("\nPersona: %s", cola->nombrePersona);
    printf("\nLocalida: %s", cola->ciudadOrigen);


    if(cola->siguiente == NULL)
        return;

    imprimirCola(cola->siguiente);

}

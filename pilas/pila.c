#include<stdio.h>
#define tamano 9

int busquedaElemento(char *pila1, int tope, char elemento);
int pilaVacia(int tope);
int pilaLlena(int topeAux);
char pop(char *pila1,int *tope);
void push(char *pilaAux, int *topeAux, char elementoPila);

int main()
{
    char pila1[9] = {'a', 'u', 't', 'o', 'm', 'o', 'v', 'i', 'l'};
    int tope = 8;
    char elemento;
    int resulBusqueda;

    printf("Dame el elemento a buscar: ");
    scanf("%c", &elemento);

    resulBusqueda = busquedaElemento(pila1, tope, elemento);

    if(resulBusqueda == -1)
        printf("No hay resulatdos mencionados");
    else
        printf("el elemento buscado esta en el indice de la pila: %d", resulBusqueda);


    return 0;
}

int busquedaElemento(char *pila1, int tope, char elemento)
{
    char pilaAux[9]= {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int topeAux = -1;
    char elementoPila;

    if(pilaVacia(tope) == 0)
        printf("Lo siento tu pila esta vacia no se puede buscar...");

    else
        while(pila1[tope] != elemento || tope > -1)
        {
            if(elemento == pila1[tope])
            {
                return tope;
            }

            if(tope == -1)
                return -1;

            elementoPila = pop(pila1, &tope);
            push(pilaAux, &topeAux, elementoPila);

            printf("\n elementos de la pila %c %s ",pilaAux[topeAux], pilaAux);


        }


        return -1;
}

int pilaVacia(int tope)
{
    if(tope < 0)
        return 0;
    else
        return 1;
}

int pilaLlena(int topeAux)
{
    if(topeAux == tamano)
        return 1;
    else
        return 0;
}

char pop(char *pila1,int *tope)
{
    char elementoPila;

    if(pilaVacia(*tope) == 0)
        printf("No se pudo quitar elemento pila vacia");
    else
    {
        elementoPila = pila1[*tope];
        pila1[*tope] = ' ';
        *tope -= 1;

        return elementoPila;

    }

    return '#';

}

void push(char *pilaAux, int *topeAux, char elementoPila)
{

    if(pilaLlena(*topeAux) == 1)
        printf("La pila esta llena no se puede agragar...");
    else
    {
        *topeAux += 1;
        pilaAux[*topeAux] = elementoPila;

    }
}

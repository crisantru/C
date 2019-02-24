#include<stdio.h>
#include<stdlib.h>

struct elementoLista insertarElementoList(struct elementoLista *inicio);
void busqueda(struct elementoLista dato);
int listaVacia(struct elementoLista *inicio);

struct elementoLista
{
    int dato;
    struct elementoLista *siguiente;            //puntero al siguiente elemento de la lista

};

struct elementoLista *inicio = NULL;

int main()
{


           //puntero "inicio" de la lista a "NULL"
    insertarElementoList(inicio);
    //busqueda(dato);

    return 0;
}

struct elementoLista insertarElementoList(struct elementoLista *inicio)
{
    inicio = (struct elementoLista *) malloc(sizeof(struct elementoLista));     //reservar memoria para el puntero al siguiente


    if (listaVacia(inicio) == 1)
        {
            inicio -> dato = 15;
            inicio -> siguiente = NULL;

        }


}

/*void busqueda(struct elementoLista dato)
{
    //nuevoElemento;

    if(listaVacia(inicio))
    {
        inicio = nuevoElemento;
        nuevoElemento -> siguiente = inicio;
        inicio = nuevoElemento;

    }


}*/

int listaVacia(struct elementoLista *inicio)
{
    if(inicio == NULL)
        return 1;
    else
        return 0;

}

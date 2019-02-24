#include<stdio.h>

int maximo(int a, int b, int c);


main()
{
    int a, b, c, respuesta;

    printf("Dame 3 numeros: ");
    scanf("%d%d%d", &a, &b, &c);

    respuesta = maximo(a, b, c);

    if(respuesta == 1)
        printf("\nNinguno es mayor...");

    printf("\nEl mayor de los tres es: %d", respuesta);

    return 0;
}

int maximo(int a, int b, int c)
{
    if(a > b && a > c)
        return a;

    if(b > a && b > c)
        return b;

    if(c > a && c > b)
        return c;

    return 1;

}

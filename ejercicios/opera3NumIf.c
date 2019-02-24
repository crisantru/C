/* Operaciones Suma, Producto, Promedio y cual es mayor de 3 numeros dados*/

#include<stdio.h>

main()
{
    float num1, num2, num3, resultado = 0;

    printf("Escribe 3 numeros: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    resultado = num1 + num2 + num3;
    printf("\nLa suma es: %.2f", resultado);

    resultado = num1 * num2 * num3;
    printf("\nEl producto es: %.2f", resultado);

    resultado = (num1 + num2 + num3)/3;
    printf("\nEl promedio es: %.2f", resultado);

    if(num1 > num2 && num1 > num3)
        printf("\nEl primer numero es mayor");

    else
        if(num2 > num1 && num2 > num3)
            printf("\nEl segundo numero es mayor");

    else
        if(num3 > num1 &&  num3 > num1)
            printf("\nEl tercer numero es mayor");
    else
        printf("\nNinguno es mayor");

    return 0;

}

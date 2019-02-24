#include<stdio.h>

main()
{
    int num1, num2;

    printf("Escribe el primer numero: ");
    scanf("%d", &num1);
    printf("Escribe el segundo numero: ");
    scanf("%d", &num2);

    if(num1 > num2)
        printf("El primer numero es mayor");
    else
        if(num2 > num1)
            printf("El segundo numero es mayor");
    else
        printf("Los dos numeros son iguales");

    return 0;

}

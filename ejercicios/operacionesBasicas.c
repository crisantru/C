#include<stdio.h>

main()
{
    float num1, num2, resultado = 0;
    int nume, nume2, resultadoe = 0;

    printf("Dame el primer numero: ");
    scanf("%f", &num1);
    printf("Dame el segundo numero: ");
    scanf("%f", &num2);
    resultado = num1 + num2;
    printf("\nLa suma es %.2f", resultado);
    resultado = num1 - num2;
    printf("\nLa resta es %.2f", resultado);
    resultado = num1 * num2;
    printf("\nLa multiplicacion es %.2f", resultado);
    resultado = num1 / num2;
    printf("\nLa division es %.2f", resultado);
  //  resultadoe = nume%nume2;        // mod solo se puede hacer entre enteros
  //  printf("El residuo es %d", resultado);

    return 0;

}

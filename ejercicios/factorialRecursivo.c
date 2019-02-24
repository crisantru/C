#include<stdio.h>

long factorial(int n);

int main()
{
    int n;
    long res;

    printf("Dame el numero para sacar su factorial: ");
    scanf("%d", &n);

    res = factorial(n);

    printf("\nEl resultado es: %lu", res);

    return 0;

}

long factorial(int n)
{
    printf("\nentra a recursion n = %d", n);
    if(n == 0)          //caso base
        return 1;

    return n * factorial(n-1);

}

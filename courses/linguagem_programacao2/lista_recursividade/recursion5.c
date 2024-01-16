#include <stdio.h>

int mdc(int, int);

int main(void)
{
    int a, b, aux;
    printf("Digite os 2 valores: ");
    scanf("%d %d", &a, &b);

    printf("\nRecursividade:\nMDC = %d\n", mdc(a,b));

    for ( ;  ; )
    {
        if (b <= a && a % b == 0) 
            break;
        else if (a < b)
            aux = a;
        else
            aux = a%b;
        a = b;
        b = aux;
    }
    printf("Iteracao:\nMDC = %d\n", b);
    return 0;
}

int mdc(int x, int y)
{
    if (y <= x && x%y == 0)
        return y;
    else if (x < y)
        return mdc(y, x);
    else
        return mdc(y, x%y);
}
/*
3. Crie 3 variaveis e associe um valor a cada uma delas. Crie 1 ponteiro e mostre o conteudo
das 3 variaveis atraves deste unico ponteiro.
*/
#include <stdio.h>

int main(void)
{
    int i, a, b, c, *ptr_abc;
    a = 4;
    b = 2;
    c = 9;
    ptr_abc = &a;
    printf("a -> %d\n", *ptr_abc);
    ptr_abc = &b;
    printf("b -> %d\n", *ptr_abc);
    ptr_abc = &c;
    printf("c -> %d\n", *ptr_abc);

    return 0;
}
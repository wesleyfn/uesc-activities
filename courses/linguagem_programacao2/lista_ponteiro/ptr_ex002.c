/*
2. Crie 3 variaveis e associe um valor a cada uma delas. Crie 3 ponteiros, um para cada vari ́avel,
e mostre o conte ́udo das vari ́aveis atrav ́es destes ponteiros.
*/
#include <stdio.h>

int main(void)
{
    int a = 10, b = 15, c = 8;
    int *ptr_a, *ptr_b, *ptr_c;
    ptr_a = &a;
    ptr_b = &b;
    ptr_c = &c;
    printf("a -> %d\nb -> %d\nc -> %d\n", *ptr_a, *ptr_b, *ptr_c);

    return 0;
}
#include <stdio.h>
#define NFIBO 10
/*
Escreva as soluções recursivas e iterativas dos problemas discutidos em sala de aula,
(fatorial, fibonacci, busca binária). Escreva e teste a solução recursiva das torres de Hanói.
Intente resolver o problema usando A, B e C para as hastes.
*/
int menu(void);
void hanoi(int, char, char, char);
int fibonacci_rec(int);
int fatorial_rec(int);

int main(void)
{
    int op, num;
    do{
        op = menu();
        switch (op)
        {
        case 1:
            printf("-> Digite o fatorial: ");
            scanf("%d", &num);
            printf("-> Fatorial de %d: %d\n\n", num, fatorial_rec(num));
            break;
        case 2:
            printf("-> Digite o n-esimo numero desejado da sequencia: ");
            scanf("%d", &num);
            printf("-> %do numero da sequencia Fibonacci: %d\n\n", num, fibonacci_rec(num));
            break;
        case 3:
            printf("-> Digite o numero de discos: ");
            scanf("%d", &num);
            hanoi(num, 'A', 'C', 'B');
            printf("\n");
            break;
        case 4:
            puts("-> Programa finalizado!");
            return 0;
            break;
        default:
            break;
        }
    } while (op != 4);
    return 0;
}

int menu(void)
{
    int n;
    printf("Escolha\n[1]Fatorial\n[2]Fibonacci\n[3]Torre de Hanoi\n[4]Sair\n::");
    scanf("%d", &n);
    return n;
}
void hanoi(int ndisc, char orig, char dest, char buffer)
{
    if (ndisc == 1){
        printf("Mover disco de %c para %c\n", orig, dest);
        return;
    }
    hanoi(ndisc-1, orig, buffer, dest);
    hanoi(1, orig, dest, buffer);
    hanoi(ndisc-1, buffer, dest, orig);
    return;
}
int fibonacci_rec(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}
int fatorial_rec(int n)
{
    if (n == 0)
        return 1;
    else
        return n*fatorial_rec(n-1);
}
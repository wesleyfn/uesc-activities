#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{  
    srand(time(NULL));
    int deck[13] = {0};
    int hand[2] = {0};
    int table[5] = {0};
    
    for (int i = 1; i < 14; i++)
    {
        deck[i] = i;
    }
    for (int i = 0; i < 2; i++)
    {
        hand[i] = rand() % 10+1;
    }
    for (int i = 0; i < 5; i++)
    {
        table[i] = rand() % 10+1;
    }

    printf("Mesa: ");
    for (int i = 0; i < 5; i++)
    {
        printf("[%2d] ", table[i]);
    }
    
    printf("\nMão:  ");
    for (int i = 0; i < 2; i++)
    {
        printf("[%2d] ", hand[i]);
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
/*
(a)
    Enderecos:
    &key: 0x7ffc182ed81a
    &choice: 0x7ffc182ed81b
    &num: 0x7ffc182ed81c
    &count: 0x7ffc182ed820
    &date: 0x7ffc182ed828
    &yield: 0x7ffc182ed824
    &price: 0x7ffc182ed830
(b)
    sizeof():
    &key: 1
    &choice: 1
    &num: 4
    &count: 4
    &date: 8
    &yield: 4
    &price: 8
*/
int main(void)
{
    char key, choice;
    int num, count;
    long int date;
    float yield;
    double price;

    puts("Enderecos:");
    printf("&key: %i\n&choice: %i\n&num: %i\n&count: %i\n", 
        sizeof(key), sizeof(choice), sizeof(num), sizeof(count));

    printf("&date: %i\n&yield: %i\n&price: %i\n", 
        sizeof(date), sizeof(yield), sizeof(price));
    
    return 0;
}
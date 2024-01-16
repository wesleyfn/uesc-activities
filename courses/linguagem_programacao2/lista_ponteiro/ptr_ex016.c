#include <stdio.h>
#include <ctype.h>

int main(void)
{   
    int i;
    char str[100], *ptr_str;

    printf("Digite a string: ");
    scanf(" %[^\n]", str);

    ptr_str = str;
    printf("a ");
    for (i = 0; *ptr_str != '\0'; i++) {
        if (tolower(*ptr_str) == 'a') printf("*");
        ptr_str++;
    }

    ptr_str = str;
    printf("\ne ");
    for (i = 0; *ptr_str != '\0'; i++) {
        if (tolower(*ptr_str) == 'e') printf("*");
        ptr_str++;
    }

    ptr_str = str;
    printf("\ni ");
    for (i = 0; *ptr_str != '\0'; i++) {
        if (tolower(*ptr_str) == 'i') printf("*");;
        ptr_str++;
    }

    ptr_str = str;
    printf("\no ");
    for (i = 0; *ptr_str != '\0'; i++) {
        if (tolower(*ptr_str) == 'o') printf("*");
        ptr_str++;
    }

    ptr_str = str;
    printf("\nu ");
    for (i = 0; *ptr_str != '\0'; i++) {
        if (tolower(*ptr_str) == 'u') printf("*");
        ptr_str++;
    }
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(void)
{
    int i;
    float Kms[MAX] = {240.5, 300.0, 189.6, 310.6, 280.7, 216.9, 199.4, 160.3, 177.4, 192.3}, 
          Lts[MAX] = {10.3, 15.6, 8.7, 14, 16.3, 15.7, 14.9, 10.7, 8.3, 8.4},
          KpL[MAX], *ptr_Kms, *ptr_Lts;

    ptr_Kms = Kms;
    ptr_Lts = &Lts[0];

    for (i = 0; i < MAX; i++)
    {
        //Utilizando subscrito no vetor e aritmetica de ponteiros
        KpL[i] = *(ptr_Kms+i) / *(ptr_Lts+i);
        printf("KpL[%d]: %.2f\n", i, KpL[i]);
    }
    return 0;
}
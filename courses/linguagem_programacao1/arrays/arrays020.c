#include<stdio.h>
#include<math.h>
int main(){

    int linha, coluna, n, a;
    int flinha, fcoluna, fb, fbinomio;
    int fl, fc, flc;


    printf("Quantidade de linhas do triangulo? ");
    scanf("%d", &n);
    printf("\n");
    n = n-1;

    for(linha=0; linha<=n; linha++){
        for(coluna=n-linha; coluna!=0; coluna--)
            printf("  ");
        for(coluna=0; coluna<=linha; coluna++){
            a=linha-coluna;
            //calula o fatorial da linha
            flinha=1;
            for(fl=linha; fl>0; fl--)
                flinha=flinha*fl;
            //calcula o fatorial da coluna
            fcoluna=1; 
            for(fc=coluna; fc>0; fc--)
                fcoluna=fcoluna*fc; 
            //Calcula o fatorial linha-coluna
            fb=1;
            for(flc=a; flc>0; flc--)
                fb=fb*flc;
            //calcula o binomio
            fbinomio=flinha/(fcoluna * fb);
            printf("%4d", fbinomio);
        }
        printf("\n");    
    }
    return 0;
}
//1- faça um programa para ler um numero inteiro positivo e informe se ele é primo
//   assumimos que para este exercicio que o numero 1 não é primo.
//   todos os outros numeros primos são numeros que so tem dois divisores 1 e ele mesmo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ehnum ( char a[] )
{
    int i;
    for (i = 0 ; i < strlen(a) ; i++)
        if ( !isdigit(a[i]) )
            return 0;
        else if (a[0] == '0' || a[0] == '\n')
            return 0;
    return 1;
}

int main ()
{
    int res, multiplo = 0, i, tam;
    char s[1000], k;
    do
    {
        printf("Insira o numero positivo e inteiro a ser analisado: "); 
        scanf("%s", s);
        while ( ehnum(s) != 1 )
        {
            printf("O valor inserido nao eh valido. Insira um numero valido: "); scanf("%s", s);
        }
        res = atoi(s);
        for (i = 1; i<=res && multiplo<1; i++) // checa se existem multiplos alem de 1 e ele mesmo
            if (res % i == 0 && i > 1 && i < res)
                multiplo+=1;
        if (multiplo > 0 || res <= 1) // se tiver algum multiplo ou for o numero 1
        {
            if (res == 69)
                printf("Nice.\n");
            printf("O numero %d nao eh primo.\n", res);
        }
        else //caso não tenha
            printf("O numero %d eh primo.\n", res);
        multiplo = 0; //reseta o contador de multiplos
        printf("Deseja continuar? [s / n] "); scanf(" %c", &k); //checa condicao de continuar e consome o \n no buffer
    } while (k == 's' || k == 'S');
    return 0;
    
}
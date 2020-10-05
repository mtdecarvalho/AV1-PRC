//8 - Faça um programa para ler dois numeros inteiros positivos e informe se eles são amigos
//   numeros amigos são numeros que a soma dos divisores de um é igual ao valor do outro.
//   obs:garanta que os numeros são positivos, caso nao seja repita a leitura.
//   ex: 220 e 284
//      Os divisores de 220 são 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110, cuja soma é 284
//      Os divisores de 284 são 1, 2, 4, 71 e 142, cuja soma é 220

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMMAX 1000

int main ()
{
    long int n1, n2, i, k = 0;
    int div1[TAMMAX], div2[TAMMAX], soma1, soma2;
    char input1[TAMMAX], input2[TAMMAX];
    char * l;
    puts("Insira os dois numeros (positivos e inteiros) a serem comparados:");
    scanf("%s %[^\n]s", input1, input2);
    n1 = strtol(input1, &l, 10); n2 = strtol(input2, &l, 10);
    while (strtol(input1, &l, 10) == 0 || strtol(input2, &l, 10) == 0 || n1 < 0 || n2 < 0)
    {
        printf("Por favor, insira numeros validos.\n"); scanf("%s %[^\n]s", input1, input2);
        n1 = strtol(input1, &l, 10); n2 = strtol(input2, &l, 10);
    }
    for (i = 1 , k = 0 ; i <= n1 ; i++)
    {
        if (n1 % i == 0)
        {
            div1[k] = i; k++;
        }
    }
    for (i = 1 , k = 0 ; i <= n2 ; i++)
    {
        if (n2 % i == 0)
        {
            div2[k] = i; k++;
        }
    }
    for (i = 0 ; div1[i] != n1 ; i++)
        soma1 += div1[i];
    for (i = 0 ; div2[i] != n2 ; i++)
        soma2 += div2[i];
    if (soma1 == n2 && soma2 == n1)
        printf("%d e %d sao numeros amigos.\n", n1, n2);
    else
        printf("%d e %d nao sao numeros amigos.\n", n1, n2);
    return 0;
}
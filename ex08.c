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

void limpartela()
{
    #ifdef __unix__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #endif
}

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    int n1, n2, i, k = 0;
    int div1[TAMMAX], div2[TAMMAX], soma[3];
    char p;

    do
    {
        limpartela();
        printf("Insira os dois numeros (positivos e inteiros) a serem comparados: ");
        while ( scanf(" %d", &n1) != 1 || scanf(" %d", &n2) != 1 || n1 < 0 || n2 < 0 )
        { 
            printf("\nValores invalidos! Tente novamente:\n"
                    "\nInsira os dois numeros (positivos e inteiros) a serem comparados: "); limpa();
        }
        limpa();
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
            soma[0] += div1[i];
        for (i = 0 ; div2[i] != n2 ; i++)
            soma[1] += div2[i];
        if (soma[0] == n2 && soma[1] == n1)
            printf("\n\t%d e %d sao numeros amigos.\n", n1, n2);
        else
            printf("\n\t%d e %d nao sao numeros amigos.\n", n1, n2);
        printf("\nDeseja reiniciar o programa? [s / n]\t"); scanf(" %c", &p); limpa();
        memset(soma, 0, sizeof(soma));
    }
    while (p == 's' || p == 'S');

    return 0;
}

        //scanf("%s %[^\n]s", input1, input2);
        //n1 = strtol(input1, &l, 10); n2 = strtol(input2, &l, 10);
        //while (strtol(input1, &l, 10) == 0 || strtol(input2, &l, 10) == 0 || n1 < 0 || n2 < 0)
        //{
        //    printf("Por favor, insira numeros validos.\n"); scanf("%s %[^\n]s", input1, input2);
        //    n1 = strtol(input1, &l, 10); n2 = strtol(input2, &l, 10);
        //}
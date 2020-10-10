//4- Faça um programa que leia duas matrizes de reais (de no maximo 100x100), e mostre o resultado da soma
//   caso nao seja possivel somar escreva "Matrizes incompativeis para a soma!" 

#include <stdio.h>

#define MAX 100

int ehnum ( char a[] )
{
    int i;
    for (i = 0 ; i < strlen(a) ; i++)
        if ( !isdigit(a[i]) )
            return 0;
    return 1;
}

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    int linha[2], coluna[2], i, j;
    double M1[MAX][MAX], M2[MAX][MAX], res[MAX][MAX];
    char p;

    do 
    {
        do
        {
            printf("Insira o numero de linhas e colunas da primeira matriz: ");
            while ( scanf(" %d", &linha[0]) != 1 || scanf(" %d", &coluna[0]) != 1 || linha[0] < 0 || coluna[0] < 0  || linha[0] > 100 || coluna[0] > 100 )
            {
                printf("Valores invalidos! Tente novamente.\n");
                printf("Insira o numero de linhas e colunas da primeira matriz: "); limpa();
            }
            printf("Insira o numero de linhas e colunas da segunda matriz: ");
            while ( scanf(" %d", &linha[1]) != 1 || scanf(" %d", &coluna[1]) != 1 || linha[1] < 0 || coluna[1] < 0  || linha[1] > 100 || coluna[1] > 100 )
            {
                printf("Valores invalidos! Tente novamente.\n");
                printf("Insira o numero de linhas e colunas da segunda matriz: "); limpa();
            }
            if ( linha[0] != linha[1] || coluna[0] != coluna[1] )
                printf("Matrizes incompativeis para a soma!\n");
        }
        while ( linha[0] != linha[1] || coluna[0] != coluna[1] );

        printf("\tMATRIZ 1\n");
        printf("Preencha as proximas %d linhas com os valores das %d colunas:\n", linha[0], coluna[0]);
        for (i = 0 ; i < linha[0] ; i++)
        {
            for (j = 0 ; j < coluna[0] ; j++)
                scanf(" %lf", &M1[i][j]);
        }
        printf("\tMATRIZ 2\n");
        printf("Preencha as proximas %d linhas com os valores das %d colunas:\n", linha[1], coluna[1]);
        for (i = 0 ; i < linha[1] ; i++)
        {
            for (j = 0 ; j < coluna[1] ; j++)
                scanf(" %lf", &M2[i][j]);
        }

        //SOMATORIO
        for (i = 0 ; i < linha[1] ; i++)
            for (j = 0 ; j < coluna[1] ; j++)
                res[i][j] = M1[i][j] + M2[i][j];

        printf("\tRESULTADO DA SOMA:\n");
        for (i = 0 ; i < linha[1] ; i++)
        {
            for (j = 0 ; j < coluna[1] ; j++)
                printf("%.2lf\t",res[i][j]);
            printf("\n");
        }
        printf("Deseja reiniciar o programa? [s / n]\n"); scanf(" %c", &p); limpa();
        memset(res, 0, sizeof(res)); memset(M1, 0, sizeof(M1)); memset(M2, 0, sizeof(M2));
    }
    while (p == 's' || p == 'S');

    return 0;
}
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

    do
    {
        printf("Insira o numero de linhas e colunas da primeira matriz: "); scanf(" %d", &linha[0]); scanf(" %d", &coluna[0]); 
        while ( linha[0] < 0 || coluna[0] < 0 )
        {
            printf("Valores invalidos!\n");
            printf("Insira o numero de linhas e colunas da primeira matriz: "); scanf(" %d", &linha[0]); scanf(" %d", &coluna[0]);
        }
        printf("Insira o numero de linhas e colunas da segunda matriz: ");
        scanf(" %d", &linha[1]); scanf(" %d", &coluna[1]);
        while ( linha[1] < 0 || coluna[1] < 0 )
        {
            printf("Valores invalidos!\n");
            printf("Insira o numero de linhas e colunas da segunda matriz: "); scanf(" %d", &linha[1]); scanf(" %d", &coluna[1]);
        }
        if ( linha[0] != linha[1] || coluna[0] != coluna[1] )
            printf("Matrizes incompativeis para a soma!\n");
    }
    while ( linha[0] != linha[1] || coluna[0] != coluna[1] );

    printf("MATRIZ 1\n");
    for (i = 0 ; i < linha[0] ; i++)
    {
        printf("Preencha as colunas da linha %d:\n", i+1);
        for (j = 0 ; j < coluna[0] ; j++)
            scanf(" %lf", &M1[i][j]);
    }
    printf("MATRIZ 2\n");
    for (i = 0 ; i < linha[1] ; i++)
    {
        printf("Preencha as colunas da linha %d:\n", i+1);
        for (j = 0 ; j < coluna[1] ; j++)
            scanf(" %lf", &M2[i][j]);
    }

    //SOMATORIO
    for (i = 0 ; i < linha[1] ; i++)
        for (j = 0 ; j < coluna[1] ; j++)
            res[i][j] = M1[i][j] + M2[i][j];

    printf("RESULTADO DA SOMA:\n");
    for (i = 0 ; i < linha[1] ; i++)
    {
        for (j = 0 ; j < coluna[1] ; j++)
            printf("%.2lf\t",res[i][j]);
        printf("\n");
    }
    return 0;
}
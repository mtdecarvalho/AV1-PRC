//5- Faça um programa que leia duas matrizes de reais (de no maximo 100x100), e mostre o resultado da multiplicação 
//   caso nao seja possivel multiplicar escreva "Matrizes incompativeis para a multiplicacao!"

#include <stdio.h>

#define MAX 100

void limpa ()
{
    while ((getchar()) != '\n');
}

int main ()
{
    int linha[2], coluna[2], i, j, k;
    double M1[MAX][MAX], M2[MAX][MAX], res[MAX][MAX], somaprod;

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
        if ( coluna[0] != linha[1] )
            printf("Matrizes incompativeis para multiplicacao!\n");
    }
    while ( coluna[0] != linha[1] );

    printf("MATRIZ 1\n");
    printf("Preencha as proximas %d linhas com os valores das %d colunas:\n", linha[0], coluna[0]);
    for (i = 0 ; i < linha[0] ; i++)
    {
        for (j = 0 ; j < coluna[0] ; j++)
        {
            scanf(" %lf", &M1[i][j]); printf(" %lf\n", M1[i][j]);
        }
    limpa();    
    }
    printf("MATRIZ 2\n");
    printf("Preencha as proximas %d linhas com os valores das %d colunas:\n", linha[1], coluna[1]);
    for (i = 0 ; i < linha[1] ; i++)
    {
        for (j = 0 ; j < coluna[1] ; j++)
        {
            scanf(" %lf", &M1[i][j]); printf(" %lf\n", M1[i][j]);
        }
    limpa();
    }

    for (i = 0 ; i < linha[0] ; i++)                                //M[1][1] * M[1][1] -> M[1][2] * M[2][1] -> M[1][3] * m[3][1]
        for (j = 0 ; j < coluna[1] ; j++)
        {
            somaprod = 0;
            for (k = 0 ; k < linha[0] ; k++)
                somaprod+=M1[i][k]*M2[k][j];
            res[i][j] = somaprod;
        }    
    
    printf("RESULTADO\n");
    for (i = 0 ; i < linha[0] ; i++)
    {
        for (j = 0 ; j < coluna[1] ; j++)
            printf("%.2lf\t",res[i][j]);
        printf("\n");
    }
    return 0;
}
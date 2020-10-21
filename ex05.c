//5- Faça um programa que leia duas matrizes de reais (de no maximo 100x100), e mostre o resultado da multiplicação 
//   caso nao seja possivel multiplicar escreva "Matrizes incompativeis para a multiplicacao!"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

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
    int linha[3], coluna[3], i, j, k;
    double M1[MAX][MAX], M2[MAX][MAX], res[MAX][MAX], somaprod;
    char p;

    do
    {
        limpartela();
        do
        {
            printf("Insira o numero de linhas e colunas da primeira matriz: ");
            while ( scanf(" %d", &linha[0]) != 1 || scanf(" %d", &coluna[0]) != 1 || linha[0] < 0 || coluna[0] < 0  || linha[0] > 100 || coluna[0] > 100 )
            {
                printf("\n\tValores invalidos! Tente novamente.\n"
                        "\nInsira o numero de linhas e colunas da primeira matriz: "); limpa();
            }
            limpa();

            printf("\nInsira o numero de linhas e colunas da segunda matriz: ");
            while ( scanf(" %d", &linha[1]) != 1 || scanf(" %d", &coluna[1]) != 1 || linha[1] < 0 || coluna[1] < 0  || linha[1] > 100 || coluna[1] > 100 )
            {
                printf("\n\tValores invalidos! Tente novamente.\n"
                        "\nInsira o numero de linhas e colunas da segunda matriz: "); limpa();
            }
            if ( coluna[0] != linha[1] )
                printf("\n\tMatrizes incompativeis para multiplicacao!\n");
        }
        while ( coluna[0] != linha[1] );
        limpa();

        printf("\n\t\t\tMATRIZ 1\n");
        printf("Preencha com os valores da matriz [%d linhas x %d colunas]:\n", linha[0],coluna[0]);
        for (i = 0 ; i < linha[0] ; i++)
        {
            printf("Linha %d: ", i+1);
            for (j = 0 ; j < coluna[0] ; j++)
            while (scanf(" %lf", &M1[i][j]) != 1)
            {
                printf("Valor invalido detectado na coluna %d. Digite um valor valido para esta coluna:\n", j+1);
                limpa();
            }
            limpa();
        }
        printf("\n\t\t\tMATRIZ 2\n");
        printf("Preencha com os valores da matriz [%d linhas x %d colunas]:\n", linha[1],coluna[1]);
        for (i = 0 ; i < linha[1] ; i++)
        {
            printf("Linha %d: ", i+1);
            for (j = 0 ; j < coluna[1] ; j++)
                while (scanf(" %lf", &M2[i][j]) != 1)
                {
                    printf("Valor invalido detectado na coluna %d. Digite um valor valido para esta coluna:\n", j+1);
                    limpa();
                }
            limpa();
        }

        for (i = 0 ; i < linha[0] ; i++)    
            for (j = 0 ; j < coluna[1] ; j++)
            {
                somaprod = 0;
                for (k = 0 ; k < coluna[0] ; k++)
                    somaprod+=M1[i][k]*M2[k][j];
                res[i][j] = somaprod;
            }    

        printf("\n\t\t\tRESULTADO:\n");
        for (i = 0 ; i < linha[0] ; i++)
        {
            for (j = 0 ; j < coluna[1] ; j++)
                printf("%.2lf\t",res[i][j]);
            printf("\n");
        }
        printf("\nDeseja reiniciar o programa? [s / n]\n"); scanf(" %c", &p); limpa();
        memset(res, 0, sizeof(res)); memset(M1, 0, sizeof(M1)); memset(M2, 0, sizeof(M2));
    } 
    while (p == 's' || p == 'S');
    return 0;
}
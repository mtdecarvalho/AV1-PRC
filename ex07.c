//7- Faça um programa que leia n e depois os dados de n alunos (no maximo 100), 
//   ao final o programa deve listar o nome de todos os alunos com media maior que a media da turma.
//   Dados dos alunos: Nome 30 caracteres, Nota1 e Nota2 reais.
//                     media = (Nota1 + 2*Nota2) / 3

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

typedef struct {
    char nome[30];
    double n1, n2, media;
} tipoalunos;

int main ()
{
    int n, i = 0, k, lixo;
    char N[4], j;
    double mediaturma;
    tipoalunos alunos[100];
    
    do
    {
        limpartela();   printf("Insira o numero de alunos a serem registrados: ");
        while ( scanf(" %d", &n) != 1 || scanf(".%d", &lixo) == 1 || n > 100 || n <= 0 )
        {   limpa(); printf("O valor inserido nao eh um numero valido. Tente novamente: "); }
        if (n > 1)
            printf("\nPreencha as proximas %d linhas com os dados dos %d alunos: \n"
                    "|NOTA MIN: 0| |NOTA MAX: 10|\tEx: Matheus 10.0 10.0\n\n", n, n);
        else
            printf("\nPreencha a proxima linha com os dados do unico aluno:\n"
                    "|NOTA MIN: 0| |NOTA MAX: 10|\tEx: Matheus 10.0 10.0\n\n");
        limpa();
        for (i = 0 ; i < n ; i++)
        {
            while (scanf(" %s", alunos[i].nome) != 1 || scanf(" %lf", &alunos[i].n1) != 1 || scanf(" %lf", &alunos[i].n2) != 1
                         || alunos[i].n1 > 10 || alunos[i].n2 > 10 || alunos[i].n1 < 0 || alunos[i].n2 < 0)
            {
                limpa();
                printf("\nOs dados foram inseridos incorretamente. Favor seguir o modelo:\n|NOTA MIN: 0| |NOTA MAX: 10|\tEx: Matheus 10.0 10.0\n\n");
            }
            limpa();
            alunos[i].media = (alunos[i].n1 + 2*alunos[i].n2) / 3;
        }
        for (i = 0 ; i < n ; i++)
        {  
            mediaturma += alunos[i].media;
        }
        mediaturma /= n; printf("\nMedia da turma: %.2lf\n\n", mediaturma);
        for (i = 0, k = 0 ; i < n ; i++)
            if (alunos[i].media > mediaturma)
            {   
                if ( k == 0 ) { printf("Os seguintes alunos possuem media de notas maior do que a da turma:\n\n"); }
                printf("Nome: %s\t\tMedia: %.2lf\n", alunos[i].nome, alunos[i].media); k++;
            }
            else if (i == n-1 && k == 0)
                printf("Nao ha nenhum aluno com media maior do que a media da turma.\n");
        printf("\nDeseja reiniciar o programa? [s / n]\t"); scanf(" %c", &j); limpa();
        mediaturma = 0; memset(alunos, 0 , sizeof(alunos));
    }
    while (j == 's' || j == 'S');
    
    return 0;
}
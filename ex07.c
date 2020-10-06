//7- Faça um programa que leia n e depois os dados de n alunos (no maximo 100), 
//   ao final o programa deve listar o nome de todos os alunos com media maior que a media da turma.
//   Dados dos alunos: Nome 30 caracteres, Nota1 e Nota2 reais.
//                     media = (Nota1 + 2*Nota2) / 3

#include <stdio.h>

int ehnum ( char a[] )
{
    int i;
    for (i = 0 ; i < strlen(a) ; i++)
        if ( !isdigit(a[i]) )
            return 0;
    return 1;
}

typedef struct {
    char nome[30];
    double n1, n2, media;
} Taluno;

int main ()
{
    int n, i = 0, k;
    char N[10], j;
    double mediaturma;
    Taluno alunos[100];
    do
    {
        printf("Insira o numero de alunos a serem registrados: "); scanf("%s", N); while ((getchar()) != '\n');
        while (ehnum(N)!=1)
        {   printf("O valor inserido nao eh um numero valido. Tente novamente: ");  scanf("%s", N); while ((getchar()) != '\n');   }
        n = atoi(N);
        printf("Preencha as proximas %d linhas com os dados dos alunos: \n"
                "Ex: Matheus 10.0 10.0\n", n);
        for (i = 0 ; i < n ; i++)
        {
            while (scanf("%s", alunos[i].nome) == 0 || scanf("%lf", &alunos[i].n1) == 0 || scanf("%lf", &alunos[i].n2) == 0
                         || alunos[i].n1 > 10 || alunos[i].n2 > 10)
            {
                while ((getchar()) != '\n');
                printf("Os dados foram inseridos incorretamente. Favor seguir o modelo:\nEx: Matheus 10.0 10.0\n");
            }
            alunos[i].media = (alunos[i].n1 + 2*alunos[i].n2) / 3;
        }
        for (i = 0 ; i < n ; i++)
        {  
            //printf("%s: %.2lf\n", alunos[i].nome, alunos[i].media);
            mediaturma += alunos[i].media;
        }
        mediaturma /= n; printf("\nMedia da turma: %.2lf\n\n", mediaturma);
        for (i = 0, k = 0 ; i < n ; i++)
            if (alunos[i].media > mediaturma)
            {   
                printf("Os seguintes alunos possuem media de notas maior do que a da turma:\n");
                printf("Nome: %s\tMedia: %.2lf\n", alunos[i].nome, alunos[i].media); k++;
            }
            else if (i == n-1 && k == 0)
                printf("\nNao ha nenhum aluno com media maior do que a media da turma.\n");
        printf("\nDeseja reiniciar o programa? [s / n]\n"); scanf(" %c", &j); while ((getchar()) != '\n');
    } while (j == 's' || j == 'S');
    return 0;
}
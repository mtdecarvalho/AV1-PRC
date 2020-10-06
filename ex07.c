//7- Faça um programa que leia n e depois os dados de n alunos (no maximo 100), 
//   ao final o programa deve listar o nome de todos os alunos com media maior que a media da turma.
//   Dados dos alunos: Nome 30 caracteres, Nota1 e Nota2 reais.
//                     media = (Nota1 + 2*Nota2) / 3

#include <stdio.h>

typedef struct {
    char nome[30];
    double n1, n2, media;
} Taluno;

int ehnum ( char a[] )
{
    int i;
    for (i = 0 ; i < strlen(a) ; i++)
        if ( !isdigit(a[i]) )
            return 0;
    return 1;
}

//usar fgets() para ler o input, strtok() para separar as entradas e strtof() para converter para float as notas.

int main ()
{
    int n, i = 0, k;
    char N[10];
    double mediaturma;
    Taluno alunos[100];
    printf("Insira o numero de alunos a serem registrados: "); scanf("%s", N);
    while (ehnum(N)!=1)
    {   printf("O valor inserido nao eh um numero valido. Tente novamente: ");  scanf("%s", N);   }
    n = atoi(N);
    printf("Preencha as proximas %d linhas com os dados dos alunos: \n"
            "Ex: Matheus 10.0 10.0\n", n);
    for (i = 0 ; i < n ; i++)
    {
        while (scanf("%s %lf %lf", alunos[i].nome, &alunos[i].n1, &alunos[i].n2) != 3)
        {
            printf("Os dados foram inseridos incorretamente. Favor seguir o modelo:\nEx: Matheus 10.0 10.0\n");
            scanf("%s %lf %lf", alunos[i].nome, &alunos[i].n1, &alunos[i].n2);
        }
        alunos[i].media = (alunos[i].n1 + 2*alunos[i].n2) / 3;
    }
    for (i = 0 ; i < n ; i++)
    {  
        printf("%s %lf\n", alunos[i].nome, alunos[i].media);
        mediaturma += alunos[i].media;
    }
    mediaturma /= n; printf("%lf\n", mediaturma);
    //for (i = 0 ; i < n ; i ++)
    //{
    //    if (alunos[i].media > mediaturma)
    //        k = 1;
    //    else if (i == n-1 && k != 1)
    //        k = 0;
    //}
    //if (k == 1)
        for (i = 0 ; i < n ; i++)
            if (alunos[i].media > mediaturma)
                printf("%s\n", alunos[i].nome);
    //else if (k != 1)
    //    printf("Nenhum aluno possui media maior que a turma.\n");        
    return 0;
}
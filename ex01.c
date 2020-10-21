//1- faça um programa para ler um numero inteiro positivo e informe se ele é primo
//   assumimos que para este exercicio que o numero 1 não é primo.
//   todos os outros numeros primos são numeros que so tem dois divisores 1 e ele mesmo.

#include <stdio.h>
#include <stdlib.h>

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
    long int n, i, tam;
    int multiplo;
    char k;
    
    do
    {
        multiplo = 0; limpartela();
        printf("Insira o numero positivo e inteiro a ser analisado: "); 
        while (scanf(" %ld", &n) != 1 || n <= 0 )
        {
            limpartela();
            printf("\tO valor inserido eh invalido!\n"
                    "\nInsira o numero positivo e inteiro a ser analisado: "); limpa();
        }
        limpa();
        
        for (i = 1; i<=n && multiplo<1; i++)
            if (n % i == 0 && i > 1 && i < n)
                multiplo+=1;

        if (multiplo > 0 || n == 1)
            printf("\n\tO numero %ld nao eh primo.\n", n);
        else
            printf("\n\tO numero %ld eh primo.\n", n);
    
        printf("\nDeseja continuar? [s / n]\t"); scanf(" %c", &k); limpa();
    }
    while (k == 's' || k == 'S');
    
    return 0;
}
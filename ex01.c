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
    int res, i, tam, multiplo;
    char k;
    
    do
    {
        multiplo = 0; limpartela();
        printf("Insira o numero positivo e inteiro a ser analisado: "); 
        while (scanf(" %d", &res) != 1 || res <= 0 )
        {
            limpartela();
            printf("\tO valor inserido eh invalido!\n"
                    "\nInsira o numero positivo e inteiro a ser analisado: "); limpa();
        }
        limpa();
        
        for (i = 1; i<=res && multiplo<1; i++)
            if (res % i == 0 && i > 1 && i < res)
                multiplo+=1;

        if (multiplo > 0 || res == 1)
            printf("\n\tO numero %d nao eh primo.\n", res);
        else
            printf("\n\tO numero %d eh primo.\n", res);
    
        printf("\nDeseja continuar? [s / n]\t"); scanf(" %c", &k); limpa();
    }
    while (k == 's' || k == 'S');
    
    return 0;
}